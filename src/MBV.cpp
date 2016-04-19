/*Copyright (C) 2015 Olivier Delaneau, Halit Ongen, Emmanouil T. Dermitzakis
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include "mode_match/match_data.h"

int main(int argc, char ** argv) {

	//1. Start timing
	timer running_timer;

	//2. Open LOG file if necessary
	for (int a = 1 ; a < argc - 1 ; a ++) {
		if ((strcmp(argv[a], "--log") == 0) && !vrb.open_log(string(argv[a+1]))) vrb.error("Impossible to open log file!");
		if (strcmp(argv[a], "--silent") == 0) vrb.set_silent();
	}

	//3. Print header on screen
	vrb.ctitle("MBV");
	vrb.bullet("Authors : Alexandre FORT / Emmanouil DERMITZAKIS / Olivier DELANEAU");
	vrb.bullet("Contact : Alexandre.Fort@unige.ch  / olivier.delaneau@gmail.com");
	vrb.bullet("Webpage : https://github.com/odelaneau/MBV");
	vrb.bullet("Version : " + string(QTLTOOLS_VERSION));
	vrb.bullet("Date    : " + running_timer.date());

	//4. Switch mode
	vector < string > args;
    if (argc < 2) args.push_back("--help");
	for (int a = 1 ; a < argc ; a ++) args.push_back(string(argv[a]));
    
	match_main(args);

	//5. Terminate
	vrb.title("Running time: " + stb.str(running_timer.abs_time()) + " seconds");
	vrb.close_log();
}
