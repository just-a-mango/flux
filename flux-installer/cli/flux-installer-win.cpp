#include <stdio.h>
#include <iostream>
#include <string>

std::string menu() {
    std::cout << "+--------------\033[32mFlux Installer\033[0m---------------+" << std::endl << "| 1. Build and install Flux\033[31m(requires g++)\033[0m   |" << std::endl << "| 2. Download and install Flux from source  |" << std::endl << "+-------------------------------------------+" << std::endl << "[+] Chosen option (1 or 2): ";
    std::string option;
    std::cin >> option;
    return option;
}


int main() {
    std::string chosen = "0";
    chosen = menu();
    if (chosen != "1" && chosen != "2") {
        while (chosen != "1" && chosen != "2") {
            chosen = menu();
        }
    }
    return 0;
}