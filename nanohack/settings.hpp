namespace settings {
	std::string data_dir = xorstr_("vos.club");
	bool cheat_init = false;

	bool panic = false;

	namespace tr {
		bool manipulated = false;
	}
}

uintptr_t game_assembly = 0;
uintptr_t unity_player = 0;