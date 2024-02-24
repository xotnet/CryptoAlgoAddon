#include <iostream>
#include <bitset>
int main(int argc, char** argv) {
	if (argv[1] && argv[2]) {
		std::cout << "Crypting: " << argv[1] << ", using key: " << argv[2] << '\n';
		std::string message = argv[1];
		std::string key = argv[2];
		std::string cryptedBin = "";
		std::string preBin = "";
		for (char c : message) {
			std::bitset<8> bits(c); // bitset is container with size 8
			preBin += bits.to_string();
		}
		for (int i = 0; i < preBin.length(); i++) { // every bit of message
			bool thisBitOfMessage, eqBitOfMessage = 0;
			if (preBin[i] == '1') {thisBitOfMessage = 1; eqBitOfMessage = 1;} else {thisBitOfMessage = 0; eqBitOfMessage = 0;}
			for (int u = 0; u < key.length(); u++) { // every char of key
				std::bitset<8> keyCharToBit(key[u]);
				for (int m = 0; m < 8; m++) { // every bit of key's symbol
					if (keyCharToBit[m] != eqBitOfMessage) {
						if (thisBitOfMessage == 1) {thisBitOfMessage = 0;} 
						else if (thisBitOfMessage == 0) {thisBitOfMessage = 1;}
					}
				}
			}
			cryptedBin = cryptedBin + std::to_string(thisBitOfMessage);
		}
		std::cout << "Encrypted bits: " << cryptedBin;
	} else {
		std::cout << "Usage: crypt [message] [password]";
	}
}
