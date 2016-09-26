#include <stdio.h>
#include <string.h>


int word_count(char * str)
{
	int num = 0;
	int i = 0;
                                       /*str[0] = 'O';segmentation fault core dumped*/

	while(str[i] != '\0')
	{
		if((str[i] != ' ')  && ((str[i + 1] == ' ') || (str[i + 1] == '\0')))
			{
				num++;
			}
		i++;
	}
	
	return num;
}



void eg6_8()
{
	int num;
	char * str = "if tired, change ur mind and use new method!";

	num = word_count("one two three");

	printf("word num = %d\n", num);
}



void book_6_8()
{
	char str[80];
	int i = 0;
	int num = 0;
	int word = 0;
	char c;
	
	strcpy(str, "one two threee four five six seven eight nine ten zero");
	
	while((c = str[i]) != '\0')
	{
		if(c == ' ')
		{
			word = 0;
		}
		else if(word == 0)	      
		{
			word = 1;
			num++;
		}

		i++;
	}

	printf("There are %d words in this line.\n", num);
}



int main()
{
	eg6_8();	
	book_6_8();
	
	return 0;
}




