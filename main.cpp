#include <iostream>
#include <bitset>
int main(int argc, char** argv) {
	if (argv[1] && argv[2] && argc == 3) {
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
			}
			cryptedBin = cryptedBin + bits.to_string();
		}
		std::cout << "Encrypted bits: " << cryptedBin;
	}
	else if (argv[3] == "-d" || argc == 4) { // decrypt
		std::string decryptedBin = "";
		std::string toCharFromBin = "";
		std::string message = argv[1]; // message here is encrypted bitset
		std::string key = argv[2];
		for (int i = 0; i < message.length(); i = i + 8) {
			std::string bitsPreset = "";
			for (int e = 0; e < 8; e++) {
				bitsPreset = bitsPreset + message[e+i];
			}
			std::bitset<8> bits(bitsPreset); // bitset is container with size 8
			for (int u = 0; u < key.length(); u++) { // bitset in key char
				std::bitset<8> keyCharToBit(key[u]);
				bits = bits ^ keyCharToBit;
			}
			decryptedBin = decryptedBin + bits.to_string();
			toCharFromBin = toCharFromBin + static_cast<char>(bits.to_ulong());
		}
		std::cout << "DecryptedMessage: " << toCharFromBin << "\nDecrypted bits: " << decryptedBin;
	}
	else {
		std::cout << "Usage: crypt [message] [password]";
	}
}
