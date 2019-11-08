#include "data.h"
#include "detour.h"
#include "main.h"
#include "console.h"
#include "TestingFuncs.h"


using namespace std; 

const char * DR2BGNAMES[1000][255] = { 

	//000
	{
		"bg_000_00_file2.dat"
		"bg_000_00_opt.dat",
		"bg_000_00_place2.dat",
		"bg_000_00_bone_pos.dat",
		"bg_000_p00.gmo",
		"floor_dummy_00.tga",
		"wall_dummy_00.tga"},

	//001
	{
		"bg_001_00_file2.dat",
		"bg_001_00_opt.dat",
	"bg_001_00_place2.dat",
	"bg_001_00_bone_pos.dat",
	"bg_001_p00t0d.gmo",
	"bg_001_p01t0d.gmo"         ,
	"bg_001_p02t0.gmo"          ,
	"bg_001_p03t1s00.gmo"       ,
	"bg_001_p04t1s01.gmo"       ,
	"bg_001_p05t1s02.gmo"       ,
	"bg_001_p06t1s03.gmo"       ,
	"bg_001_p07t1s04.gmo"       ,
	"bg_001_p08t1s05.gmo"       ,
	"bg_001_p09t1s06.gmo"       ,
	"bg_001_p10t1s07.gmo"       ,
	"bg_001_p11t1s08.gmo"       ,
	"bg_001_p12t1s09.gmo"       ,
	"bg_001_p13t1s10.gmo"       ,
	"bg_001_p14t1s11.gmo"       ,
	"bg_001_p15t1s12.gmo"       ,
	"bg_001_p16t1s13.gmo"       ,
	"bg_001_p17t1s14.gmo"       ,
	"bg_001_p18t1a0d.gmo"       ,
	"bg_001_p19t1a0.gmo"        ,
	"bg_001_p20t1a0d.gmo"       ,
	"bg_001_p21t3.gmo"          ,
	"bg_001_p22d.gmo"           ,
	"bg_001_p23t0d.gmo"         ,
	"bg_001_p24t1s15.gmo"       ,
	"bg_001_p25t1s16.gmo"       ,
	"bg_001_p26t1s17.gmo"       ,
	"bg_001_p27t1s18.gmo"       ,
	"bg001_tvcam.tga"           ,
	"bg_001_haibis00_uv.tga"    ,
	"bg_025_kemuri.tga"         ,
	"bg_025_seacret_kuma_01.tga",
	"capusel.tga"               ,
	"chara_shadow_00.tga"       ,
	"dr2_e01sea00.tga"          ,
	"dr2_e01sea01_uv.tga"       ,
	"dr2_e01sea02.tga"          ,
	"dr2_e01sea04.tga"          ,
	"dr2_e0gake00_uv.tga"       ,
	"dr2_e0gake01_uv.tga"       ,
	"dr2_e0_grass00_uv.tga"     ,
	"dr2_e0_sand00.tga"         ,
	"dr2_e0_sand01.tga"         ,
	"dr2_e0_sky00.tga"          ,
	"dr2_e0_sky01_uv.tga"       ,
	"dr2_e0_sky02_uv.tga"       ,
	"dr2_e0_sky03_uv.tga"       ,
	"dr2_e0_sky04_uv.tga"       ,
	"dr2_e0_yashi00_uv.tga"     ,
	"dr2_e0_yashi01_uv.tga"     ,
	"dr2_e0_yashi02_uv.tga"     ,
	"dr2_e0_yashi03_uv.tga"     ,
	"dr2_e0_yashi04_uv.tga"     ,
	"dr2_e0_yashi05_uv.tga"     ,
	"kamome.tga"                ,
	"monotv2_00.tga"            ,
	"monoyasi_obj03.tga"        ,
	"seacret_kuma_00.tga"},

	//002
	{
		"bg_002_00_file2.dat",
		"bg_002_00_opt.dat"
		,"bg_002_00_place2.dat"
		,"bg_002_00_bone_pos.dat"
		,"bg_002_p00ld.gmo"
		,"bg_002_p01ld.gmo"
		,"bg_002_p02a0t0ld.gmo"
		,"bg_002_p03a0t0ld.gmo"
		,"bg_002_p04.gmo"
		,"bg_002_p05a0.gmo"
		,"bg_002_p06t0.gmo"
		,"bg_002_p07t0.gmo"
		,"bg_002_p08s0.gmo"
		,"bg_002_p09s1.gmo"
		,"bg_002_p10s2.gmo"
		,"bg_002_p11s3.gmo"
		,"bg_002_p12s4.gmo"
		,"bg_002_p13s5.gmo"
		,"bg_002_p14d.gmo"
		,"bg_002_p15a0t0.gmo"
		,"bg_002_p16a2t0.gmo"
		,"bg_002_bosuton.tga"
		,"bg_002_dimen.tga"
		,"bg_002_erv.tga"
		,"bg_002_erv00.tga"
		,"bg_002_erv01.tga"
		,"bg_002_hasira.tga"
		,"bg_002_hikouki00.tga"
		,"bg_002_hikouki01.tga"
		,"bg_002_isu.tga"
		,"bg_002_kabe.tga"
		,"bg_002_kabe00.tga"
		,"bg_002_kabe01.tga"
		,"bg_002_kanban.tga"
		,"bg_002_kanban00.tga"
		,"bg_002_kikai00.tga"
		,"bg_002_mado.tga"
		,"bg_002_mado00.tga"
		,"bg_002_mado_r.tga"
		,"bg_002_monokuma.tga"
		,"bg_002_monotv2.tga"
		,"bg_002_pai.tga"
		,"bg_002_porl.tga"
		,"bg_002_porl00.tga"
		,"bg_002_road.tga"
		,"bg_002_seacret_kuma_01.tga"
		,"bg_002_sky.tga"
		,"bg_002_sky_n.tga"
		,"bg_002_toranku.tga"
		,"bg_002_tvcame.tga"
		,"bg_021_hikari.tga"
		,"bg_025_kemuri.tga"
		,"bg_163_yasi.tga"
		,"chara_shadow_00.tga"
		,"dr2_yashi03_uv.tga"},

	//003
	{
	"bg_003_00_file2.dat"
	,"bg_003_00_opt.dat"
	,"bg_003_00_place2.dat"
	,"bg_003_00_bone_pos.dat"
	,"bg_003_p00.gmo"
	,"bg_003_p01t0.gmo"
	,"bg_003_p02t3a2.gmo"
	,"bg_003_p03t1.gmo"
	,"bg_003_p04s0t1.gmo"
	,"bg_003_p05s1t1.gmo"
	,"bg_003_p06s2t1.gmo"
	,"bg_003_p07s3t1.gmo"
	,"bg_003_p08s4t1.gmo"
	,"bg_003_p09s5t1.gmo"
	,"bg_003_p10d.gmo"
	,"bg_003_cart.tga"
	,"bg_003_drink_00.tga"
	,"bg_003_drink_01.tga"
	,"bg_003_farstocker_0.tga"
	,"bg_003_farstocker_1.tga"
	,"bg_003_farstocker_2.tga"
	,"bg_003_farstocker_3.tga"
	,"bg_003_floor_00.tga"
	,"bg_003_glass.tga"
	,"bg_003_icecream.tga"
	,"bg_003_light_00.tga"
	,"bg_003_milk.tga"
	,"bg_003_parts_00.tga"
	,"bg_003_parts_01.tga"
	,"bg_003_parts_02.tga"
	,"bg_003_parts_10.tga"
	,"bg_003_prise_00.tga"
	,"bg_003_sports_00.tga"
	,"bg_003_sports_01.tga"
	,"bg_003_stocker_00.tga"
	,"bg_003_surf_00.tga"
	,"bg_003_wall_00.tga"
	,"bg_003_wall_01.tga"
	,"bg_003_wood_00.tga"
	,"bg_003_zihanki_02.tga"
	,"bg_003_zihanki_03.tga"
	,"bg_003_zihanki_04.tga"
	,"bg_003_zihanki_05.tga"
	,"bg_025_kemuri.tga"
	,"chara_shadow_00.tga"
	,"monocam_01.tga"
	,"monotv_00.tga"
	,"seacret_kuma_003.tga"
	},
			
	//004
	{
		"bg_004_00_file2.dat"
		,"bg_004_00_opt.dat"
		,"bg_004_00_place2.dat"
		,"bg_004_00_bone_pos.dat"
		,"bg_004_p00d.gmo"
		,"bg_004_p01d.gmo"
		,"bg_004_p02a0.gmo"
		,"bg_004_p03s0.gmo"
		,"bg_004_p04s1.gmo"
		,"bg_004_p05s2.gmo"
		,"bg_004_p06s3.gmo"
		,"bg_004_p07s4.gmo"
		,"bg_004_p08s5.gmo"
		,"bg_004_p09t3a0.gmo"
		,"bg_004_p10t1a0.gmo"
		,"bg_004_p11t1.gmo"
		,"bg_004_p12t0a0.gmo"
		,"bg_004_bird_00.tga"
		,"bg_004_cock.tga"
		,"bg_004_cow_00.tga"
		,"bg_004_farm_00.tga"
		,"bg_004_fence_00.tga"
		,"bg_004_fence_01.tga"
		,"bg_004_ground_00.tga"
		,"bg_004_ground_01.tga"
		,"bg_004_monocam.tga"
		,"bg_004_mt_00.tga"
		,"bg_004_mt_01.tga"
		,"bg_004_tree_00.tga"
		,"bg_004_woods_00_v.tga"
		,"bg_004_yashi_00.tga"
		,"chara_shadow_00.tga"
		,"monotv2_05.tga"
		,"sky_00.tga"
		,"sky_01.tga"
	}

};

DWORD OPCOdeFuncs[256] = {0x0};

void grabOPThing()
{
	_asm
	{
		mov edx, OPCOdeFuncs[eax * 4]
	}
}

const Functions::FunctionData Functions::DR2functions[1] = {
	{0x332A0, 0x10E,  Sound::VoiceLineMaths,  "FUNC_VOICEMATH"}//, 
	//{0x7D2BE, 0x7,  grabOPThing,  "INST_ReadOPFunc"}
};

void Functions::HookFunctions()
{
	//Detour::HookStringPtr(0x7D2C1, (DWORD)&OPCOdeFuncs);
	//Console::WriteLine(std::to_string(Detour::GrabPointer(0x7D2C1)).c_str());
	//Console::WriteLine(std::to_string((DWORD)&Sound::VoiceLineMaths).c_str());
	
	for (int a = 0; a < 1; a++)
	{
		Detour::Hook(Functions::DR2functions[a].Address, Functions::DR2functions[a].Replacement, Functions::DR2functions[a].Size);
		Console::WriteLine("%s has been hooked!", Functions::DR2functions[a].Name);
	}
}

void Data::HookBGFileNames()
{

	for (int a = 0; a < 77; a++)
	{
		DWORD result = Detour::GrabPointer(0x30B910 + (4 * a));
		Console::WriteLine(std::to_string(result).c_str());
		if(result != 0)
		{
			OPCOdeFuncs[a] = result;
		};
	}

	OPCOdeFuncs[0xFF] = (DWORD)&TestingFuncs::CustomOPCodeTest;


//
//
//
//	for (int a = 0; a < 1000; a++)
//	{
//
//		string path = "mod_data\manifest\modelbg\bg_%03d.txt";
//		string line;
//
//		ifstream BGManifest(path);
//
//		if (BGManifest.is_open()) {
//			Console::WriteLine("file is open");
//
//
//			while(BGManifest.eof)
//			{
//				getline(BGManifest, line);
//			}
//
//
//
//			string BackgroundThings[5];
//
//			for (int i = 0; i < 5; ++i)
//			{
//				BGManifest >> BackgroundThings[i];
//			}
//
//		}
//
//
//		//const char * test = (const char*[])DR2BGArrayPointer;
//		//(char)DR2BGArrayPointer;
//		//if(*bg001[a] != 0)
//		//*bg001[a] = (const char[])DR2BGArrayPointer + (4 * a);//
//		//reinterpret_cast<const char*>(Detour::GrabPointer(DR2BGArrayPointer + (4 * a)));
//		//{
//		//	Console::WriteLine(bg001[a][0]);
//		//}
}

