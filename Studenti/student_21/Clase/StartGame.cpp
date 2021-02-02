#include "SceneManager.h"
using namespace std;




int main()
{
	SceneManager& myManager = SceneManager::getInstance();
	myManager.setNextScene(new UIPrefab<UIPrefabs::MenuScene>());
	while (myManager.Run());
	myManager.releaseInstance();
}
