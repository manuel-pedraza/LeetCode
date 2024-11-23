#include "functions.h"

//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
//https://stackoverflow.com/questions/9965710/how-to-change-text-and-background-color

bool isVowel(char letter)
{
	return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
		|| letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I'
		|| letter == 'O' || letter == 'U';
}
