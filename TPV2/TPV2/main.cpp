#include <iostream>

#include "StarWars.h"
#include "Networking.h"

using namespace std;



void server(int port) {
	Networking net;
	net.server(port);
}

void client(char* host, int port, char* name) {
	try {
		StarWars g(host, port,name);
		g.start();
	}
	catch (std::string& e) { // catch errors thrown as strings
		cerr << e << endl;
	}
	catch (const std::exception& e) { // catch other exceptions
		cerr << e.what();
	}
	catch (...) {
		cerr << "Caught and exception of unknown type ..";
	}

}


int main(int argc, char** argv) {
	if (argc == 3 && strcmp(argv[1], "server") == 0) {
		server(atoi(argv[2])); // start in server mode
	}
	else if ((argc == 4  || argc == 5) && strcmp(argv[1], "client") == 0 ) {
		if (argc == 5 && strlen(argv[4]) > 10) {
			cout << "El nombre debe tener 10 caracteres o menos" << endl;
		}
		else {
			if (argc == 5 && strlen(argv[4]) <= 10)
			{
				client(argv[2], atoi(argv[3]), argv[4]); // start in client mode

			}
			else if (argc == 4)
			{
				char an[11] = "Anonymous";
				client(argv[2], atoi(argv[3]), an); // start in client mode

			}
		}
	}

	else {
		cout << "Usage: " << endl;
		cout << "  " << argv[0] << " client host port " << endl;
		cout << "  " << argv[0] << " server port " << endl;
		cout << endl;
		cout << "Example:" << endl;
		cout << "  " << argv[0] << " server 2000" << endl;
		cout << "  " << argv[0] << " client localhost 2000" << endl;
	}

	return 0;
}
