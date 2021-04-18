#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

SceneID startScene, scene1, scene2, scene3, scene4, scene5;
ObjectID start, startBtn, next, next2, next3, next4, end, box[36];
SoundID background, success, fail, move;
clock_t timeStart, timeEnd;

int x = 250, y = 500;
int movement = 75;
int leftCount = 0, rightCount = 0, upCount = 0, downCount = 0;
int count = 0, sum = 0;
int maxCount = 25;
bool isDone = false;
int coord[36], fire[36];
char sec[50];

int indexToX(int i) {
	return 250 + 75 * (i % 6);
}

int indexToY(int i) {
	return 500 - 75 * (i / 6);
}

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}

	return object;
}

void gameInit() {
	memset(fire, -1, 36 * sizeof(fire[0]));
	timeStart = clock();
	isDone = false;
	leftCount = 0, rightCount = 0, upCount = 0, downCount = 0, count = 0;
	x = 250, y = 500;
	srand(static_cast<unsigned int>(time(NULL)));
	success = createSound("Sound/success.mp3");
	fail = createSound("Sound/fail.mp3");
	move = createSound("Sound/move.mp3");
	startScene = createScene("", "Images/black.jpg");
	startBtn = createObject("Images/start.jpg", startScene, 400, 300, true);
	end = createObject("Images/end.png", startScene, 400, 300, false);
	scene1 = createScene("Stage 1", "Images/black.jpg");
	next = createObject("Images/next.png", scene1, 750, 300, false);

	for (int i = 0; i < 35; i++) {
		box[i] = createObject("Images/box.jpg", scene1, indexToX(i), indexToY(i), true);
		scaleObject(box[i], 0.5f);
		coord[i] = i;
	}
	int j = 0;
	for (int i = 1; i <= 25; i += 6) {
		int num = rand() % 30 + 2;
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 9; i <= 33; i += 6) {
		int num = rand() % 30 + 2;
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	
	box[35] = createObject("Images/blueBox.jpg", scene1, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);
	start = createObject("Images/yellow.png", scene1, x, y, true);
	scaleObject(start, 0.33f);
}

void game2Init() {
	memset(fire, -1, 36 * sizeof(fire[0]));
	isDone = false;
	leftCount = 0, rightCount = 0, upCount = 0, downCount = 0, count = 0;
	x = 250, y = 500;
	srand(static_cast<unsigned int>(time(NULL)));
	scene2 = createScene("Stage 2", "Images/black.jpg");
	next2 = createObject("Images/next.png", scene2, 750, 300, false);

	for (int i = 0; i < 35; i++) {
		box[i] = createObject("Images/box.jpg", scene2, indexToX(i), indexToY(i), true);
		scaleObject(box[i], 0.5f);
		coord[i] = i;
	}
	int j = 0;
	for (int i = 6; i <= 10; i++) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;        
	}
	for (int i = 19; i <= 23; i++) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 25; i <= 33; i += 4) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	
	box[35] = createObject("Images/blueBox.jpg", scene2, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);
	start = createObject("Images/yellow.png", scene2, x, y, true);
	scaleObject(start, 0.33f);
}

void game3Init() {
	memset(fire, -1, 36 * sizeof(fire[0]));	isDone = false;
	leftCount = 0, rightCount = 0, upCount = 0, downCount = 0, count = 0;
	x = 250, y = 500;
	srand(static_cast<unsigned int>(time(NULL)));
	scene3 = createScene("Stage 3", "Images/black.jpg");
	next3 = createObject("Images/next.png", scene3, 750, 300, false);

	for (int i = 0; i < 35; i++) {
		box[i] = createObject("Images/box.jpg", scene3, indexToX(i), indexToY(i), true);
		scaleObject(box[i], 0.5f);
		coord[i] = i;
	}
	int j = 0;
	for (int i = 7; i <= 10; i++) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 18; i <= 30; i+=6) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 20; i <= 23; i++) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}

	box[35] = createObject("Images/blueBox.jpg", scene3, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);

	start = createObject("Images/yellow.png", scene3, x, y, true);
	scaleObject(start, 0.33f);
}

void game4Init() {
	memset(fire, -1, 36 * sizeof(fire[0]));	isDone = false;
	leftCount = 0, rightCount = 0, upCount = 0, downCount = 0, count = 0;
	x = 250, y = 500;
	srand(static_cast<unsigned int>(time(NULL)));
	scene4 = createScene("Stage 4", "Images/black.jpg");
	next4 = createObject("Images/next.png", scene4, 750, 300, false);

	for (int i = 0; i < 35; i++) {
		box[i] = createObject("Images/box.jpg", scene4, indexToX(i), indexToY(i), true);
		scaleObject(box[i], 0.5f);
		coord[i] = i;
	}
	int j = 0;
	for (int i = 6; i <= 10; i+=2) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 19; i <= 23; i += 2) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 30; i <= 34; i += 2) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}

	box[35] = createObject("Images/blueBox.jpg", scene4, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);
	start = createObject("Images/yellow.png", scene4, x, y, true);
	scaleObject(start, 0.33f);
}

void game5Init() {
	memset(fire, -1, 36 * sizeof(fire[0]));	isDone = false;
	leftCount = 0, rightCount = 0, upCount = 0, downCount = 0, count = 0;
	x = 250, y = 500;
	srand(static_cast<unsigned int>(time(NULL)));
	scene5 = createScene("Stage 5", "Images/black.jpg");
	end = createObject("Images/end.png", scene5, 750, 300, false);

	for (int i = 0; i < 35; i++) {
		box[i] = createObject("Images/box.jpg", scene5, indexToX(i), indexToY(i), true);
		scaleObject(box[i], 0.5f);
		coord[i] = i;
	}
	int j = 0;
	for (int i = 7; i <= 10; i++) {
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	for (int i = 18; i <= 30; i++) {
		if (i == 20 || i == 21 || i == 22 || i == 27) continue;
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	box[35] = createObject("Images/blueBox.jpg", scene5, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);
	start = createObject("Images/yellow.png", scene5, x, y, true);
	scaleObject(start, 0.33f);
}

bool isGameSuccess(int l, int r, int u, int d) {
	if (r - l == 5 && d - u == 5) return true;
	return false;
}

bool isFire(int l, int r, int u, int d) {
	for (int i = 0; i < 36; i++) {
		if ((d - u) * 6 + (r - l) == fire[i]) {
			return true;
		}
	}
	return false;
}

void moveRight() {
	if (rightCount - leftCount < 5) {
		playSound(move);
		x += movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		locateObject(start, scene4, x, y);
		locateObject(start, scene5, x, y);
		rightCount++;
		count++;
		sum++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {
			stopSound(move);
			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			timeEnd = clock();
			sprintf(sec, "You are in fire!! Time : %.0lfsec Count : %d  ToTal : %d", (double)(timeEnd - timeStart) / CLOCKS_PER_SEC, count, sum);
			playSound(fail);
		}
		printf("%d\n", count);
		
	}
}
void moveLeft() {
	if (leftCount < rightCount) {
		playSound(move);
		x -= movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		locateObject(start, scene4, x, y);
		locateObject(start, scene5, x, y);
		leftCount++;
		count++;
		sum++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {

			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			playSound(fail);
			timeEnd = clock();
			sprintf(sec, "You are in fire!! Time : %.0lfsec Count : %d  ToTal : %d", (double)(timeEnd - timeStart) / CLOCKS_PER_SEC, count, sum);
			showMessage(sec);
		}

		printf("%d\n", count);
	}
}
void moveUp() {
	if (upCount < downCount) {
		playSound(move);
		y += movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		locateObject(start, scene4, x, y);
		locateObject(start, scene5, x, y);
		upCount++;
		count++;
		sum++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {

			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			playSound(fail);
			timeEnd = clock();
			sprintf(sec, "You are in fire!! Time : %.0lfsec Count : %d  ToTal : %d", (double)(timeEnd - timeStart) / CLOCKS_PER_SEC, count, sum);
		}
		printf("%d\n", count);
	}
}
void moveDown() {
	if (downCount - upCount < 5) {
		playSound(move);
		y -= movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		locateObject(start, scene4, x, y);
		locateObject(start, scene5, x, y);
		downCount++;
		count++;
		sum++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {

			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			timeEnd = clock();
			sprintf(sec, "You are in fire!! Time : %.0lfsec Count : %d  ToTal : %d", (double)(timeEnd - timeStart) / CLOCKS_PER_SEC, count, sum);
			showMessage(sec);
			playSound(fail);
		}

		printf("%d\n", count);
	}
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startBtn) {
		gameInit();
		enterScene(scene1);
	}
	if (object == next) {
		game2Init();
		enterScene(scene2);
	}
	if (object == next2) {
		game3Init();
		enterScene(scene3);
	}
	if (object == next3) {
		game4Init();
		enterScene(scene4);
	}
	if (object == next4) {
		game5Init();
		enterScene(scene5);
	}
	if (object == end) endGame();

}

void keyboardCallback(KeyCode code, KeyState state) {
	if (!isDone) {
	
		if (isGameSuccess(leftCount, rightCount, upCount, downCount)) {
			stopSound(move);
			playSound(success);
			timeEnd = clock();
			sprintf(sec, "Success!! Time : %.0lfsec Count : %d  ToTal : %d", (double)(timeEnd - timeStart) / CLOCKS_PER_SEC, count, sum);
			showMessage(sec);
			showObject(next);
			showObject(next2);
			showObject(next3);
			showObject(next4);
			showObject(end);
			isDone = true;
		}
		if (count >= maxCount) {
			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			playSound(fail);
			timeEnd = clock();
			sprintf(sec, "Fail!! Time : %.0lfsec", (double)(timeEnd - timeStart) / CLOCKS_PER_SEC);
			showMessage(sec);
			isDone = true;
		}
		if (code == KeyCode::KEY_RIGHT_ARROW && state == KeyState::KEY_PRESSED) {
			moveRight();
		}
		else if (code == KeyCode::KEY_LEFT_ARROW && state == KeyState::KEY_PRESSED) {
			moveLeft();
		}
		else if (code == KeyCode::KEY_UP_ARROW && state == KeyState::KEY_PRESSED) {
			moveUp();
		}
		else if (code == KeyCode::KEY_DOWN_ARROW && state == KeyState::KEY_PRESSED) {
			moveDown();
		}
	}


}

int main() {
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, true);

	setMouseCallback(mouseCallback);
	setKeyboardCallback(keyboardCallback);

	gameInit();
	
	startGame(startScene);
}