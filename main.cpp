#include <windows.h>

#include "MigratoryDataLogLevel.h"
#include "MigratoryDataListener.h"
#include "MigratoryDataClient.h"
#include "MigratoryDataLogListener.h"
#include "MigratoryDataLogLevel.h"

#include "config.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace migratorydata;

class MLogListener : public MigratoryDataLogListener
{

public:
	void onLog(string& log, MigratoryDataLogLevel logLevel)
	{
		cout << "Got Log: " << log << endl;
	}

};

class MListener : public MigratoryDataListener
{

public:
	void onMessage(const MigratoryDataMessage& message)
	{
		cout << "Got message: " << endl;
		cout << message.toString() << endl;
	}

	void onStatus(const string& status, string& info)
	{
		cout << "Got status: " << status << " " << info << endl;
	}
};

void start()
{
	MigratoryDataClient* client = new MigratoryDataClient();

	// configure the logging
	MigratoryDataLogListener* myLogListener = new MLogListener();
	client->setLogListener(myLogListener, LOG_TRACE);

	client->setEntitlementToken(TOKEN);

	client->setEncryption(ENCRYPTION);

	// define the listener for messages and notifications
	MigratoryDataListener* myListener = new MListener();
	client->setListener(myListener);

	vector<string> servers;
	servers.push_back(SERVER);
	client->setServers(servers);

	vector<string> subjects;
	subjects.push_back(SUBJECT);
	client->subscribe(subjects);
	client->connect();

	// publish a message every 5 seconds
	int count = 0;
	while (count++ < 100)
	{
		ostringstream content;
		content << "some-content-" << count;

		ostringstream closure;
		closure << "some-closure-" << count;

		MigratoryDataMessage message(SUBJECT, content.str(), closure.str());

		client->publish(message);

		Sleep(5000);
	}

	client->disconnect();

	delete myLogListener;
	delete myListener;
	delete client;
}

int main(int argc, char* argv[])
{
	start();

	return 0;
}
