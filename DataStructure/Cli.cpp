//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Cli.h"

#pragma mark Util

void printWelcomeInfo() {
    std::cout << "Welcome Info" << std::endl;
}

void printHelpInfo() {
    std::cout << "Help Info" << std::endl;
}

#pragma mark -
#pragma mark Cli

/**
 * Process the command line input
 */
void Cli::process(std::string command) {
    
}

/**
 *  Command line interface
 */
void Cli::start() {
    // Print welcome information
    printWelcomeInfo();
    
    // Print help information
    printHelpInfo();
    
    // Infinite loop
    while (true) {
        std::string command;
        std::cout << "> ";
        std::cin >> command;
        
        this->process(command);
    }
}