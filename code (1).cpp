#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <cctype>

int recieveCount = 0;
int sendCount = 0;
std::string word;

std::string FRIEND1Facebook = "REDACTEDUSERNAME:</b></font>";
std::string FRIEND1Steam = "<b>REDACTEDUSERNAME:</b></font>";

std::string FRIEND5 = "<b>REDACTEDUSERNAME:</b></font>";
std::string FRIEND52 = "<b>REDACTEDUSERNAME";

std::string BROTHER1gtalk = "<b>REDACTEDUSERNAME";

std::string FRIEND2Steam = "<b>REDACTEDUSERNAME:</b></font>";
std::string FRIEND2Facebook = "REDACTEDUSERNAME:</b></font>";

std::string FRIEND3Facebook = "REDACTEDUSERNAME:</b></font>";
std::string FRIEND3Steam = "REDACTEDUSERNAME:</b></font>";
std::string FRIEND3gtalk = "<b>REDACTEDUSERNAME:</b></font>";

std::string FRIEND4Facebook = "<b>REDACTEDUSERNAME";
std::string FRIEND4Steam = "REDACTEDUSERNAME:</b></font>";
std::string FRIEND4Skype = "REDACTEDUSERNAME:</b></font>";
std::string FRIEND4AOL = "<b>REDACTEDUSERNAME:</b></font>";

std::string myFacebook = "<b>REDACTEDUSERNAME";
std::string myAOL = "<b>REDACTEDUSERNAME/";
std::string mySteam = "<b>REDACTEDUSERNAME:</b></font>";
std::string mySteam2 = "REDACTEDUSERNAME:</b></font>";
std::string mySteam3 = "<b>REDACTEDUSERNAME:</b></font>";

using namespace std;

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

int main()
{
	ofstream myfile;
	myfile.open ("record.txt");
	myfile << "fileDate" << "\t" << "me" << "\t" << "him" << "\n";
	HANDLE hFind = FindFirstFile("*.html", &FindFileData);
	
	while (hFind != INVALID_HANDLE_VALUE)
	{
		sendCount = 0;
		recieveCount = 0;
		ifstream readFile;
		readFile.open(FindFileData.cFileName);
		while(readFile >> word)
		{
			if((word == FRIEND1Facebook || word == FRIEND1Steam) || (word == FRIEND5 || word == FRIEND52) || (word == BROTHER1gtalk) || (word == FRIEND2Steam || word == FRIEND2Facebook) || (word == FRIEND3Facebook || word == FRIEND3Steam || word == FRIEND3gtalk) || (word == FRIEND4Facebook || word == FRIEND4Steam || word == FRIEND4Skype || word == FRIEND4AOL))
			{
			recieveCount++;
			}
			else if(word == myFacebook || word == myAOL || word == mySteam || word == mySteam2 || word == mySteam3)
			{
				sendCount++;
			}
			else
			{
			word = word.substr(0, 21);
				if(word == "<b>REDACTEDEMAIL/")
				{
				sendCount++;
				}
			}
		}
//		2013-04-21.104313-0400EDT.html
		std::string text = FindFileData.cFileName;
		std::string year = text.substr(0, 4);
		std::string month = text.substr(5, 2);
		std::string day = text.substr(8, 2);
		std::string time = text.substr(11, 4);
		
		string fileDate = month + "/" + day + "/" + year;
		myfile << fileDate << "\t" << sendCount << "\t" << recieveCount << "\n";
		cout << "You  sent " << sendCount << " messages" << endl;
		cout << "They sent " << recieveCount << " messages" << endl;
	
		if (!FindNextFile(hFind, &FindFileData))
		{
			FindClose(hFind);
			hFind = INVALID_HANDLE_VALUE;
		}
	}
myfile.close();
cin >> word;
return 0;
}