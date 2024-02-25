#include <iostream>
#include <bitset>
int main(int argc, char** argv) {
	if (argv[1] && argv[2]) {
		std::cout << "Crypting: " << argv[1] << ", using key: " << argv[2] << '\n';
		std::string message = argv[1];
		std::string key = argv[2];
		std::string cryptedBin = "";
		std::string preBin = "";
		for (char c : message) { // every char in message
			std::bitset<8> bits(c); // bitset is container with size 8
			for (int u = 0; u < key.length(); u++) { // bitset in key char
				std::bitset<8> keyCharToBit(key[u]);
				bits = bits ^ keyCharToBit;
				bits = bits & keyCharToBit;
			}
			cryptedBin = cryptedBin + bits.to_string();
		}
		std::cout << "Encrypted bits: " << cryptedBin;
	} else {
		std::cout << "Usage: crypt [message] [password]";
	}
}
