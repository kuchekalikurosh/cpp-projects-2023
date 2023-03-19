#include <iostream>
#include <string>

using namespace std;

class Zipcode {
    public:
        int digit;
        int checksum;
        int sum = 0;
        int sum2 = 0;
        string mickey = "";
        string temp = "";
        string convert;
        string fullbar = "|";
        string binary = "";
        char barcode;

        void Convert(string temp) {
            for(int i = 0; i < 30; i++) {
                barcode = temp[i];
                if(barcode == '1') {
                    fullbar += "|";
                } else {
                    fullbar += ":";
                }
            }
            fullbar += "|";
            cout << fullbar;
        }

        string Checksum(string zipcode) {
            for(int i = 0; i < 5; i++) {
                sum += zipcode[i];
            }
            sum = 10 - (sum % 10);
            zipcode += to_string(sum);
            return zipcode;
        }

        string BinaryConverter(string zipcode) {
            for(int i = 0; i < 6; i++) {
                digit = zipcode[i] - '0';
                if(digit == 9) {
					temp += "10100";
				}
				else if(digit == 8) {
					temp += "10010";
				}
				else if(digit == 7) {
					temp += "10001";
				}
				else if(digit == 6) {
					temp += "01100";
				}
				else if(digit == 5) {
					temp += "01010";
				}
				else if(digit == 4) {
					temp += "01001";
				}
				else if(digit == 3) {
					temp += "00110";
				}
				else if(digit == 2) {
					temp += "00101";
				}
				else if(digit == 1) {
					temp += "00011";
				}
				else if(digit == 0){
					temp += "11000";
				}
				else {
					cout << "Error!";
					break;
				}
            }
            return temp;
        }
};

int main() {
    string zipcode;
    string barcode;
    Zipcode input;

    cout << "Enter Zipcode: \n";
    cin >> zipcode;
    input.Convert(input.BinaryConverter(input.Checksum(zipcode)));

    return 0;
}