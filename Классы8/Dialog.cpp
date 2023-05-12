#include "Dialog.h"
#include <string>
using namespace std;

Dialog::Dialog()
{
	EndState = 0;
}

Dialog::~Dialog(){}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-sgqam";
	string s;
	string param;
	char code;
	cout << ">";
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm':
			event.command = cmMake;
			break;
		case '+':
			event.command = cmAdd;
			break;
		case'-':
			event.command = cmDel;
			break;
		case's':
			event.command = cmShow;
			break;
		case'q':
			event.command = cmQuit;
			break;
		case 'g':
			event.command = cmGet;
			break;
		}
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else
		event.what = evNothing;
}

int Dialog::Execute()
{
	TEvent event;
	do{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

void Dialog::HandleEvent(TEvent&event)
{
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake:
			size = event.a;
			dat = new Object*[size];
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			add();
			ClearEvent(event);
			break;
		case cmDel:
			del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

int Dialog::Valid()
{
	return EndState;
}

void Dialog::EndExec()
{
	EndState = 1;
}

