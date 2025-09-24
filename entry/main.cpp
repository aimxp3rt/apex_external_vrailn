#include "main.h"
#include <thread>
#include <iostream>
#include <Windows.h>


auto init() -> bool
{

	mem::find_driver();

	mem::process_id = mem::find_process("r5apex_dx12.exe");

	mem::CR3();

	baseaddress = mem::find_image();

	setupoverlay();

	std::thread player_thread(player_reading_work);
	std::thread glow_thread(glow_loop);
	render_loop();

	player_thread.join();
	glow_thread.join();

}

auto main() -> void
{
	SetConsoleTitleA("gurt: sybau Private. apex external, @vrailn");

	cout << "gurt: sybau private " << endl;

	if (!init())
	{

		cout << "<!> failed to gurt: sybau" << endl;
		Sleep(3000);
		exit(0);
	}

}