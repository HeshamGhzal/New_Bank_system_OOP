#include<iostream>
#include<string>
#include"client/clsBank_Client.h"
#include"clsMain_menu.h"
#include"clsLOGIN_SCREEN.h"

using namespace std;


int main()
{
   while (true)
	{
		if (!clsLogin_screen::Show_Login_Screen())
		{
			break;
		}
	}
    // clsLogin_screen::Show_Login_Screen();
    
    return 0;
}