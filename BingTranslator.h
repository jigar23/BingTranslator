
#ifndef INDEP_TRANSLATOR_H_
#define INDEP_TRANSLATOR_H_
#include <stdio.h>
#include <iostream>
#include <jni.h>
#include <string>

class Translator{
public:
	static JavaVM *jvm;
    static int count;

	Translator(){}

	/*
	This function translates the string *lang1* to the desired language.
	Input parameters:
	lang1 : string which needs to be translated.
	cliendID : Microsoft Client ID.
	clientSec : Microsoft Client Secret Key.
	translateFrom : Language of the string *lang1* [REMEMBER: This has to be the codeword of the corresponding
	language. For list of code-words, refer *list_of_languages.txt* file]
	translateTo: Language in which the translation is to be done.
	*/

	std::string translateData(std::string,std::string,std::string,std::string,std::string);

	~Translator(){
		//Close the Java VM
		int n = jvm->DestroyJavaVM();
	}

};



#endif // TRY_H_INCLUDED 