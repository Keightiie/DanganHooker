#include "console.h"
#include "sound.h"


int CharactersLines[28][11] = {
	{565,745,926,1134,1354,1610,1848,1889,-1,-1,-1},			//0 - Hajime
	{2175,2358,2467,2626,-1,2804,2805,2905,-1,-1,-1},			//1 - Nagito
	{-1,-1,-1,-1,-1,8532,8533,8605,-1,-1,-1},					//2 - Imposter
	{8108,8144,8174,8243,-1,8394,8395,8470,-1,-1,-1},			//3 - Gundham
	{7553,7579,7618,7671,7785,7909,8001,8077,-1,-1,-1},			//4 - Soda
	{364,-1,-1,-1,-1,470,471,547,-1,-1,-1},						//5 - Teruteru
	{5631,5682,-1,-1,-1,5736,5737,5818,-1,-1,-1},				//6 - Nekomaru
	{2994,3024,3122,3194,3269,3387,3495,3576,-1,-1,-1},			//7 - Fuyuhiko
	{5871,5896,5926,6007,6099,6201,6292,6374,-1,-1,-1},			//8 - Akane
	{4920,4966,5046,5144,5227,5463,5514,5594,-1,-1,-1},			//9 - Chiaki
	{6971,6993,7021,7075,7184,7328,7428,7518,-1,-1,-1},			//10 - Sonia
	{6727,6771,-1,-1,-1,6892,6893,6956,-1,-1,-1},				//11 - Hiyoko
	{2034,-1,-1,-1,-1,2099,2100,2164,-1,-1,-1},					//12 - Mahiru
	{8614,8654,8702,-1,-1,8843,8844,8918,-1,-1,-1},				//13 - Mikan
	{3638,3678,-1,-1,-1,3732,3733,3806,-1,-1,-1},				//14 - Ibuki
	{6430,6471,-1,-1,-1,6616,6617,6699,-1,-1,-1},				//15 - Peko
	{3837,3865,3884,3899,3920,3958,4029,4129,4160,4277,4424},	//16 - Monokuma
	{4435,4458,4478,4492,4511,4544,4545,4645,-1,4651,4722},		//17 - Monomi
	{-1,-1,-1,-1,-1,0,343,-1,-1,-1,-1}, 						//18 - Junko
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},							//19 - Free
	{-1,-1,-1,-1,-1,4727,4902,4903,-1,-1,-1},					//20 - Makoto
	{-1,-1,-1,-1,-1,1980,-1,2021,-1,-1,-1},						//21 - Kirigiri 
	{-1,-1,-1,-1,-1,8482,-1,8519,-1,-1,-1},						//22 - Byakuya
	{-1,-1,-1,-1,-1,-1,-1,359,-1,-1,-1},						//23 - Teruteru Mother
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},							//24 - Free
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},							//25 - Free
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},							//26 - Free
	{-1,-1,-1,-1,-1,-1,-1,3623,-1,-1,-1}						//27 - Narrator

};


int Sound::VoiceLineMaths(int CharacterArg, int ChapterArg, int LineArg)
{

	signed int Chapter;
	int Line;
	int FileNum = 0;

	if (CharacterArg > 27) return -1;


	switch (ChapterArg)
	{
	case 1:
		Chapter = 0;
		break;
	case 2:
		Chapter = 1;
		break;
	case 3:
		Chapter = 2;
		break;
	case 4:
		Chapter = 3;
		break;
	case 5:
		Chapter = 4;
		break;
	case 6:
		Chapter = 5;
		break;

	case 8:
	case 99:
		if (LineArg >= 801)
		{
			Line = LineArg - 801;
			FileNum = CharactersLines[CharacterArg][10];
			goto LABEL_28;
		}
		if (LineArg >= 601)
		{
			Line = LineArg - 601;
			FileNum = CharactersLines[CharacterArg][9];
			goto LABEL_28;
		}
		if (LineArg >= 401)
		{
			Line = LineArg - 401;
			FileNum = CharactersLines[CharacterArg][8];
			goto LABEL_28;
		}
		if (LineArg >= 101)
		{
			Line = LineArg - 101;
			FileNum = CharactersLines[CharacterArg][7];
			goto LABEL_28;
		}
		if (LineArg >= 1)
		{
			Line = LineArg - 1;
			FileNum = CharactersLines[CharacterArg][6];
			goto LABEL_28;
		}

		return -1;
	default:
		return -1;
	}


	if (LineArg < 1) return -1;

	Line = LineArg - 1;
	FileNum = CharactersLines[CharacterArg][Chapter];


LABEL_28:

	if (FileNum == -1) return -1;
	if (Line < 0) return -1;


	FileNum += Line;
	if (FileNum >= 8965)
		return -1;
	char ResultString[300];
	std::snprintf(ResultString, 300, "Character: %d, Chapter %d, Voice: %d, File Number: %d", CharacterArg, ChapterArg, LineArg, FileNum);
	Console::WriteLine(ResultString);

	return FileNum;


}

