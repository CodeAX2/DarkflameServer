#include "SsModularBuildServer.h"
#include "MissionComponent.h"
#include "eMissionState.h"

void SsModularBuildServer::OnModularBuildExit(Entity* self, Entity* player, bool bCompleted, std::vector<LOT> modules) {
	int missionNum = 1732;

	if (bCompleted) {
		MissionComponent* mission = static_cast<MissionComponent*>(player->GetComponent(COMPONENT_TYPE_MISSION));
		Mission* rocketMission = mission->GetMission(missionNum);

		if (rocketMission->GetMissionState() == eMissionState::ACTIVE) {
			mission->ForceProgress(missionNum, 2478, 1);
		}
	}
}
