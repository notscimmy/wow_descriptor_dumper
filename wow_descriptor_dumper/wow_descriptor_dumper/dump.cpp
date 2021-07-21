#include <stdint.h>
#include <string>

#include "offsets.h"

uint64_t OBJECT_DESCRIPTORS_END_ADDRESS = 0; // -> item, unit, gameobject, dynamicobject
uint64_t OBJECT_DESCRIPTORS_END_POS = 0;

uint64_t ITEM_DESCRIPTORS_END_ADDRESS = 0; // -> container
uint64_t ITEM_DESCRIPTORS_END_POS = 0;

uint64_t UNIT_DESCRIPTORS_END_ADDRESS = 0; // -> player
uint64_t UNIT_DESCRIPTORS_END_POS = 0;

uint64_t PLAYER_DESCRIPTORS_END_ADDRESS = 0; // -> active player
uint64_t PLAYER_DESCRIPTORS_END_POS = 0;

struct RawDescriptor {
	const char* name;
	uint64_t size;
	uint64_t flags;
};

void dump_object_descriptors() {
	static std::string last_known_descriptor = "m_scale";

	uint64_t obj_desc_start_addr = GAME_BASE_ADDRESS + OBJECT_DESCRIPTORS_START;
	RawDescriptor* obj_descriptors = (RawDescriptor*)obj_desc_start_addr;

	printf("Object Descriptors\n");
	uint64_t current_pos = 0;
	while (true) {
		RawDescriptor desc = *obj_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		obj_descriptors = obj_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	OBJECT_DESCRIPTORS_END_POS = current_pos;
	printf("\n");
}

void dump_item_descriptors() {
	static std::string last_known_descriptor = "m_itemAppearanceModID";

	uint64_t item_desc_start_addr = GAME_BASE_ADDRESS + ITEM_DESCRIPTORS_START;
	RawDescriptor* item_descriptors = (RawDescriptor*)item_desc_start_addr;

	printf("Item Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *item_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		item_descriptors = item_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	ITEM_DESCRIPTORS_END_POS = current_pos;
	printf("\n");
}

void dump_container_descriptors() {
	static std::string last_known_descriptor = "m_numSlots";

	uint64_t container_desc_start_addr = GAME_BASE_ADDRESS + CONTAINER_DESCRIPTORS_START;
	RawDescriptor* container_descriptors = (RawDescriptor*)container_desc_start_addr;

	printf("Container Descriptors\n");
	uint64_t current_pos = ITEM_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *container_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		container_descriptors = container_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_unit_descriptors() {
	static std::string last_known_descriptor = "guildGUID";

	uint64_t unit_desc_start_addr = GAME_BASE_ADDRESS + UNIT_DESCRIPTORS_START;
	RawDescriptor* unit_descriptors = (RawDescriptor*)unit_desc_start_addr;

	printf("Unit Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *unit_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		unit_descriptors = unit_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
	UNIT_DESCRIPTORS_END_POS = current_pos;
}

void dump_player_descriptors() {
	static std::string last_known_descriptor = "customizationChoices";

	uint64_t player_desc_start_addr = GAME_BASE_ADDRESS + PLAYER_DESCRIPTORS_START;
	RawDescriptor* player_descriptors = (RawDescriptor*)player_desc_start_addr;

	printf("Player Descriptors\n");
	uint64_t current_pos = UNIT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *player_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		player_descriptors = player_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
	PLAYER_DESCRIPTORS_END_POS = current_pos;
}

void dump_active_player_descriptors() {
	static std::string last_known_descriptor = "overrideSpellsID";

	uint64_t active_player_desc_start_addr = GAME_BASE_ADDRESS + ACTIVE_PLAYER_DESCRIPTORS_START;
	RawDescriptor* active_player_descriptors = (RawDescriptor*)active_player_desc_start_addr;

	printf("ActivePlayer Descriptors\n");
	uint64_t current_pos = PLAYER_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *active_player_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		active_player_descriptors = active_player_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_game_object_descriptors() {
	static std::string last_known_descriptor = "m_customParam";

	uint64_t game_object_desc_start_addr = GAME_BASE_ADDRESS + GAME_OBJECT_DESCRIPTORS_START;
	RawDescriptor* game_object_descriptors = (RawDescriptor*)game_object_desc_start_addr;

	printf("GameObject Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *game_object_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		game_object_descriptors = game_object_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_dynamic_object_descriptors() {
	static std::string last_known_descriptor = "m_castTime";

	uint64_t dynamic_object_desc_start_addr = GAME_BASE_ADDRESS + DYNAMIC_OBJECT_DESCRIPTORS_START;
	RawDescriptor* dynamic_object_descriptors = (RawDescriptor*)dynamic_object_desc_start_addr;

	printf("DynamicObject Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *dynamic_object_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		dynamic_object_descriptors = dynamic_object_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_corpse_descriptors() {
	static std::string last_known_descriptor = "m_customDisplayOption";

	uint64_t dynamic_object_desc_start_addr = GAME_BASE_ADDRESS + CORPSE_DESCRIPTORS_START;
	RawDescriptor* dynamic_object_descriptors = (RawDescriptor*)dynamic_object_desc_start_addr;

	printf("Corpse Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *dynamic_object_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		dynamic_object_descriptors = dynamic_object_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_area_trigger_descriptors() {
	static std::string last_known_descriptor = "m_creatingEffectGUID";

	uint64_t dynamic_object_desc_start_addr = GAME_BASE_ADDRESS + AREA_TRIGGER_DESCRIPTORS_START;
	RawDescriptor* dynamic_object_descriptors = (RawDescriptor*)dynamic_object_desc_start_addr;

	printf("AreaTrigger Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *dynamic_object_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		dynamic_object_descriptors = dynamic_object_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_scene_object_descriptors() {
	static std::string last_known_descriptor = "m_sceneType";

	uint64_t dynamic_object_desc_start_addr = GAME_BASE_ADDRESS + SCENE_OBJECT_DESCRIPTORS_START;
	RawDescriptor* dynamic_object_descriptors = (RawDescriptor*)dynamic_object_desc_start_addr;

	printf("SceneObject Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *dynamic_object_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		dynamic_object_descriptors = dynamic_object_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}

void dump_conversation_data_descriptors() {
	static std::string last_known_descriptor = "m_lastLineEndTime";

	uint64_t dynamic_object_desc_start_addr = GAME_BASE_ADDRESS + CONVERSATION_DATA_DESCRIPTORS_START;
	RawDescriptor* dynamic_object_descriptors = (RawDescriptor*)dynamic_object_desc_start_addr;

	printf("ConversationData Descriptors\n");
	uint64_t current_pos = OBJECT_DESCRIPTORS_END_POS;

	while (true) {
		RawDescriptor desc = *dynamic_object_descriptors;
		std::string name = desc.name;

		printf("0x%08llX %s\n", current_pos, name.c_str());

		current_pos += desc.size * 4;
		dynamic_object_descriptors = dynamic_object_descriptors + desc.size;

		if (name == last_known_descriptor) {
			break;
		}
	}

	printf("\n");
}