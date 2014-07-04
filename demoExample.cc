
#include "BingTranslator.h"

using namespace std;

/**
This is a demo file which shows the translation of text from
English to Spanish.
Enter the client ID and the clientSecret before compiling 
this file.
Also export the Java libraries before compiling the files.
Refer README for more details.

Author: Jigar Gada
ContactMe: jigargada90@gmail.com
Last updated: 07/03/2014 

*/


int main(int argc, char const *argv[])
{	
	//text which has to be converted.
	string english = "Hello how are you";

	//Enter the client ID and the client Secret
	string clientID = "*******";
	string clientSec = "*******************************";

	//Convert from English to Spanish.
	//"en" and "es" are the codewords for English and Spanish respectively.
	// In order to use your languages, refer the file *list_of_languages.txt*.
	string translateFrom = "en";
	string translateTo = "es";

	//Create an object of Translator.
	Translator Tr;
	//Call the translateData fucntion.
	string spanish = Tr.translateData(english, clientID,clientSec, translateFrom, translateTo);	
	cout << "English = " << english << endl;
	cout << "Spanish = " << spanish << endl;

	//Output should be -->
	//English = Hello how are you
	//Spanish = Hola cómo estás

	return 0;
}