#include <FL/Fl.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <iostream>

using namespace std;

void send_cb(Fl_Widget*, void*);  //function prototypes

int main()
{
	Fl_Window win(600, 800, "Testing");
	win.begin();
		Fl_Return_Button send(520, 760, 70, 30, "&Send");
		Fl_Input inp(10, 760, 500, 30, "");
		Fl_Multiline_Output messagesTextView(10, 10, 580, 740, "");
	win.end();
	send.callback(send_cb);
	messagesTextView.value("");
	win.show();
	return Fl::run();
}

void send_cb(Fl_Widget* dugme, void*) {
	Fl_Return_Button* b = (Fl_Return_Button*)dugme;
	Fl_Input* in = (Fl_Input*)b->parent()->child(1);
	Fl_Multiline_Output* messagesTextView = (Fl_Multiline_Output*)b->parent()->child(2);
	const char* inText = in->value();
	cout << inText << endl;
	const char* messagesText = messagesTextView->value();
	cout << messagesText << endl;
	string inString(inText);
	string messagesTextString(messagesText);
	messagesTextView->value((messagesTextString + "\n" + inString).c_str());
	in->value("");
}
