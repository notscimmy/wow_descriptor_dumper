#include <Windows.h>
#include <string>

#include "dump.h"
#include "offsets.h"

void call_descriptor_game_routines() {
	typedef void(*DescriptorFn_t)();
	DescriptorFn_t obj_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + OBJECT_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t item_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + ITEM_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t container_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + CONTAINER_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t unit_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + UNIT_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t player_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + PLAYER_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t active_player_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + ACTIVE_PLAYER_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t game_obj_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + GAME_OBJECT_DESCRIPTORS_FN_OFFSET);
	DescriptorFn_t dyn_game_obj_desc_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + DYNAMIC_OBJECT_DESCRIPTORS_FN_OFFSET);
	// TODO
	// DescriptorFn_t corpse_descriptors_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + CORPSE_DESCRIPTORS_FN_OFFSET);
	// DescriptorFn_t area_trigger_descriptors_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + AREA_TRIGGER_DESCRIPTORS_FN_OFFSET);
	// DescriptorFn_t scene_object_descriptors_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + SCENE_OBJECT_DESCRIPTORS_FN_OFFSET);
	// DescriptorFn_t conversation_data_descriptors_fn = (DescriptorFn_t)(GAME_BASE_ADDRESS + CONVERSATION_DATA_DESCRIPTORS_FN_OFFSET);


	obj_desc_fn();
	item_desc_fn();
	container_desc_fn();
	unit_desc_fn();
	player_desc_fn();
	active_player_desc_fn();
	game_obj_desc_fn();
	dyn_game_obj_desc_fn();

	// TODO
	// corpse_descriptors_fn();
	// area_trigger_descriptors_fn();
	// scene_object_descriptors_fn();
	// conversation_data_descriptors_fn();
}

void DumpThread()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	GAME_BASE_ADDRESS = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
	call_descriptor_game_routines();

	dump_object_descriptors();
	dump_item_descriptors();
	dump_container_descriptors();
	dump_unit_descriptors();
	dump_player_descriptors();
	dump_active_player_descriptors();
	dump_game_object_descriptors();
	dump_dynamic_object_descriptors();

	// TODO
	// dump_corpse_descriptors();
	// dump_area_trigger_descriptors();
	// dump_scene_object_descriptors();
	// dump_conversation_data_descriptors();
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpBlah) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		char name[4096];

		GetModuleFileNameA(hinstDLL, name, 4096);
		LoadLibrary(name);

		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DumpThread, 0, 0, 0);
	}

	return TRUE;
}