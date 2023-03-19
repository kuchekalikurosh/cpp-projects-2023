#include <iostream>
#include <string>

using namespace std;

/* Kurosh Kuchekali
1 September 2022*/

int main() {

    string country;
    string finalName;
    int stringLegnth;

    //asks the user for a country name in French and scans the response
    cout << "Please enter a country name in French: \n\n";
    getline(cin, country);

    //this line grabs the first character of the string at index 0 (which is the first letter of any string)
    char firstCharacter = country.at(0);

    //then, the legnth of the string is taken
    stringLegnth = country.length();
    //using the length of the string, you can subtract 1 from the lenth to find the last index (last letter)
    char lastCharacter = country.at(stringLegnth - 1);
    
    //the first if statement first compares if the country is called "Etats-Unis" or "Payas-Bas" as these are special exceptions
    //then it checks for any vowls within the first letter
    if (firstCharacter == 'A' | firstCharacter == 'E' | firstCharacter == 'I' | firstCharacter == 'O' | firstCharacter == 'U' && (country != "Etats-Unis" && country != "Pays-Bas")) 
    {
        //if the condition is met, it adds "l'" to the name of the country
        finalName = "l'" + country;
    } 
    //then it checks if the last letter has an "s"
    else if (lastCharacter == 's') 
    {
        //if the condition is met, it adds "les"
        finalName = "les " + country;
    } 
    //then it checks if the last letter is an 'e' and if it does not equal the special exepctions
    else if (lastCharacter == 'e' && country != "Belize" && country != "Cambodge" && country != "Mexique" && country != "Mozambique" && country != "Zaire" && country != "Zimbabwe") 
    {
        //if the condition is met, it adds a "la"
        finalName = "la " + country;
    } 
    //if all conditions fail, it simply just adds a "le"
    else 
    {
        finalName = "le " + country; 
    }

    //finally, prints out the final output
    cout << "The proper French name of the country with it's article would be: " + finalName;

    return 0;
}