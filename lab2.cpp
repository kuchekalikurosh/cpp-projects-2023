#include <string>
#include <iostream>
#include <stack>
#include <time.h>
#include <stdio.h>

using namespace std;

//struct for each segment
struct Segment
{
    Segment *prevThis;
    Segment *nextThis;
    Segment *prevOther;
    Segment *nextOther;
    string segInfo; //for debugging
    int segNum;
    int track;
    int trainIndicator;
};

//rendering the map
void renderDiagram(Segment *seg[], int numSegTracks)
{
    //           0   1   2   3   4
    // line1 +------------------->---+
    // line2 |   x   x   x   x   x   |
    // line3 | +-------------<-----+ |
    // line4 | |                   | |
    // line5 | +--------->---------+ |
    // line6 |   x   x   x   x   x   |
    // line7 +-----------------------+
    //           9   8   7   6   5

    string ccwArrow = "";
    string cwArrow = "";
    string noTrain = "---";
    string t1[numSegTracks / 2]; // Segments Track 1 (outer track)
    string t2[numSegTracks / 2]; // Segments Track 2 (inner track)
    string line[7];              // Output lines

    for (int ts = 0; ts < numSegTracks; ts++)
    {
        ccwArrow = (seg[ts]->segNum >= 5) ? "->-" : "-<-";
        cwArrow = (seg[ts]->segNum >= 5) ? "-<-" : "->-";
        if (seg[ts]->track == 0)
        {
            if (seg[ts]->trainIndicator == 1)
            {
                t1[seg[ts]->segNum] = cwArrow;
            }
            else if (seg[ts]->trainIndicator == -1)
            {
                t1[seg[ts]->segNum] = ccwArrow;
            }
            else
            {
                t1[seg[ts]->segNum] = noTrain;
            }
        }
        else
        {
            if (seg[ts]->trainIndicator == 1)
            {
                t2[seg[ts]->segNum] = cwArrow;
            }
            else if (seg[ts]->trainIndicator == -1)
            {
                t2[seg[ts]->segNum] = ccwArrow;
            }
            else
            {
                t2[seg[ts]->segNum] = noTrain;
            }
        }
    }

    line[0] = "+--" + t1[0] + "-" + t1[1] + "-" + t1[2] + "-" + t1[3] + "-" + t1[4] + "--+";
    line[1] = "|   x   x   x   x   x   |";
    line[2] = "| +" + t2[0] + "-" + t2[1] + "-" + t2[2] + "-" + t2[3] + "-" + t2[4] + "+ |";
    line[3] = "| |                   | |";
    line[4] = "| +" + t2[9] + "-" + t2[8] + "-" + t2[7] + "-" + t2[6] + "-" + t2[5] + "+ |";
    line[5] = line[1];
    line[6] = "+--" + t1[9] + "-" + t1[8] + "-" + t1[7] + "-" + t1[6] + "-" + t1[5] + "--+";
    for (int i = 0; i <= 6; i++)
    {
        cout << line[i] << endl;
    }
}

//train movement function
void moveTrains(Segment *segTracksList[], int numSegTracks)
{
    int ccwTrain = -1;
    int cwTrain = 1;
    int noTrain = 0;
    stack<Segment *> curSegStack;
    stack<Segment *> skipSegStack;
    Segment *seg;
    for (int i = 0; i < numSegTracks; i++)
    {
        if (segTracksList[i]->trainIndicator != 0)
        {
            curSegStack.push(segTracksList[i]);
        }
    }

    do
    {
        while (!curSegStack.empty())
        {
            seg = curSegStack.top();
            if (seg->trainIndicator == ccwTrain)
            {
                if (seg->prevThis->trainIndicator == 0)
                {
                    //moving the train on the same track
                    seg->prevThis->trainIndicator = ccwTrain;
                    seg->trainIndicator = 0;
                    curSegStack.pop();
                }
                else if (seg->prevOther->trainIndicator == 0)
                {
                    //moving the train onto the other track
                    seg->prevOther->trainIndicator = ccwTrain;
                    seg->trainIndicator = 0;
                    curSegStack.pop();
                }
                else
                {
                    //deadlock prevention
                    skipSegStack.push(seg);
                    curSegStack.pop();
                }
            }
            else
            {
                if (seg->nextThis->trainIndicator == 0)
                {
                    //moving the train on the same track
                    seg->nextThis->trainIndicator = cwTrain;
                    seg->trainIndicator = 0;
                    curSegStack.pop();
                }
                else if (seg->nextOther->trainIndicator == 0)
                {
                    //moving the train onto the other track
                    seg->nextOther->trainIndicator = cwTrain;
                    seg->trainIndicator = 0;
                    curSegStack.pop();
                }
                else
                {
                    //deadlock prevention
                    skipSegStack.push(seg);
                    curSegStack.pop();
                }
            }
        }

        while (!skipSegStack.empty())
        {
            curSegStack.push(skipSegStack.top());
            skipSegStack.pop();
        }

    } while (!curSegStack.empty());
}

//debugging
void outputInfo(Segment *segTracksList[], int numSegTracks)
{
    for (int ts = 0; ts < numSegTracks; ts++)
    {
        if (segTracksList[ts]->trainIndicator == 0)
        {
            cout << segTracksList[ts]->segInfo << endl;
        }
        else
        {
            cout << segTracksList[ts]->segInfo << " Train = " << segTracksList[ts]->trainIndicator << endl;
        }
    }
}

//main function
int main()
{
    //initialization of all variables
    srand(time(NULL));
    int numSeg = 10;
    int numTracks = 2;        //track number cannot change in this logic
    int numTrainsGoLeft = 2;  //counter-clockwise
    int numTrainsGoRight = 2; //clockwise
    int rounds = 50;
    Segment segments[numTracks][numSeg];
    int numSegTrackList = numSeg * numTracks;
    Segment *segTrackList[numSegTrackList];

    //pointer assignment
    int prev = 0;
    int next = 0;
    for (int t = 0; t < numTracks; t++)
    {
        for (int s = 0; s < numSeg; s++)
        {
            // next = s + 1; if ( s == numSeg - 1 ) next = 0;
            // prev = s - 1; if ( s == 0 ) prev = numSeg - 1;
            next = (s == numSeg - 1) ? 0 : s + 1; //shorthand if statements (ternary operator)
            prev = (s == 0) ? numSeg - 1 : s - 1; //shorthand if statements (ternary operator)

            segments[t][s].segInfo = "Track=" + to_string(t) + " Segment=" + to_string(s);
            segments[t][s].segInfo += " Prev=" + to_string(prev) + " Next=" + to_string(next);
            segments[t][s].prevThis = &segments[t][prev];
            segments[t][s].nextThis = &segments[t][next];
            segments[t][s].prevOther = &segments[(t == 0) ? 1 : 0][prev];
            segments[t][s].nextOther = &segments[(t == 0) ? 1 : 0][next];
            segments[t][s].trainIndicator = 0; //initializing to 0 (no train)
            segments[t][s].segNum = s;
            segments[t][s].track = t;
        }
    }

    //creating arrays that has pointers to all segments (array of pointers)
    int cnt = 0;
    for (int t = 0; t < numTracks; t++)
    {
        for (int s = 0; s < numSeg; s++)
        {
            segTrackList[cnt++] = &segments[t][s];
        }
    }

    //populating the trains w/ direction
    stack<int> trainDirectionStack;
    for (int i = 0; i < numTrainsGoLeft; ++i)
        trainDirectionStack.push(-1);
    for (int i = 0; i < numTrainsGoRight; ++i)
        trainDirectionStack.push(1);

    //adding the trains onto the map
    int track = 0;
    int segment = 0;
    while (!trainDirectionStack.empty())
    {
        do
        {
            track = rand() % 2;
            segment = rand() % 10;
            //to avoid deadlock where none of the trains can move, placing the intial trains where the segment is empty on both tracks
            //deadlock example:
            //    track1 -->---<--
            //    track2 -->---<--
            //
        } while (segments[0][segment].trainIndicator != 0 || segments[1][segment].trainIndicator != 0);
        segments[track][segment].trainIndicator = trainDirectionStack.top();
        trainDirectionStack.pop();
    }

    //rendering the diagram w/ random assignments
    renderDiagram(segTrackList, numSegTrackList);

    //simulation based on the number of rounds
    for (int r = 0; r < rounds; r++)
    {
        //train moving function is called
        moveTrains(segTrackList, numSegTrackList);

        //rendering the iterations
        renderDiagram(segTrackList, numSegTrackList);
    }

    //output for debugging
    //outputInfo(segTrackList, numSegTrackList);

    return 0;
}
