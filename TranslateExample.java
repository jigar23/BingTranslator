//package com.memetix.mst.examples;

import com.memetix.mst.language.Language;
import com.memetix.mst.translate.Translate;

/**
 * TranslateExample
 * 
 * A short, sweet demo on how to translate a String using microsoft-translator-java-api
 * 
 * @author griggs.jonathan
 * @date Jun 1, 2011
 * @since 0.3 June 1, 2011
 */
public class TranslateExample 
{

    static String translateTextData(String language1, String clientId, String clientSecret, String translateFrom, String translateTo){

        Translate.setClientId(clientId);
        Translate.setClientSecret(clientSecret);
        String translatedText = "";
        Language tf = Language.fromString(translateFrom);
        Language tt = Language.fromString(translateTo);
        try{
            translatedText = Translate.execute(language1, tf, tt);

        }
        catch (Exception e){
             System.err.println("ERROR : " + e.getMessage());
        }
        return translatedText;
    }

    void getLanguageNames(){
        //Get the all the values in the enum and print the non-localized name (i.e. the literal name of the Enum constant)
        // this is the default way of dealing with lists of enums, but not the most user friendly way to construct a list
        System.out.println("\nLanguage Names as Enum Constants\n");
        for(Language lang : Language.values()) {
            System.out.println(lang.name() + " : " + lang.toString());
        }

    }
}
