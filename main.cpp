#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

SceneID startScene, scene1, scene2, scene3;
ObjectID start, startBtn, next, next2, next3, end, box[36];
TimerID timer1, timer2;

int x = 250, y = 500;
int movement = 75;
int leftCount = 0, rightCount = 0, upCount = 0, downCount = 0;
int count = 0;
int maxCount = 50;
bool isDone = false;
int coord[36], fire[36];

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
	isDone = false;
	leftCount = 0, rightCount = 0, upCount = 0, downCount = 0, count = 0;
	x = 250, y = 500;
	srand(static_cast<unsigned int>(time(NULL)));
	startScene = createScene("", "Images/black.jpg");
	startBtn = createObject("Images/start.jpg", startScene, 400, 400, true);
	end = createObject("Images/start.jpg", startScene, 400, 400, false);
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
	j = 0;
	for (int i = 9; i <= 33; i += 6) {
		int num = rand() % 30 + 2;
		setObjectImage(box[i], "Images/redBox.jpg");
		fire[j] = i;
		j++;
	}
	/*
	for (int i = 0, j = 0; i <= 10; i++) {
		int num = rand() % 30 + 2;
		setObjectImage(box[num], "redBox.jpg");
		fire[j] = num;
		j++;
	}
	*/
	box[35] = createObject("Images/blueBox.jpg", scene1, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);
	start = createObject("Images/yellow.png", scene1, x, y, true);
	scaleObject(start, 0.33f);
}

void game2Init() {
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

	for (int i = 0, j = 0; i <= 10; i++) {
		int num = rand() % 30 + 2;
		setObjectImage(box[num], "Images/redBox.jpg");
		fire[j] = num;
		j++;
	}

	box[35] = createObject("Images/blueBox.jpg", scene2, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);
	start = createObject("Images/yellow.png", scene2, x, y, true);
	scaleObject(start, 0.33f);
}

void game3Init() {
	isDone = false;
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

	for (int i = 1, j = 9, k = 0; i <= 25, j <= 32; i += 6, j += 6) {
		int num = rand() % 30 + 2;
		setObjectImage(box[i], "Images/redBox.jpg");
		setObjectImage(box[j], "Images/redBox.jpg");
		fire[k] = i;
		fire[k + 1] = j;
		k += 2;
	}

	box[35] = createObject("Images/blueBox.jpg", scene3, indexToX(35), indexToY(35), true);
	scaleObject(box[35], 0.5f);

	start = createObject("Images/yellow.png", scene3, x, y, true);
	scaleObject(start, 0.33f);
}

bool isGameSuccess(int l, int r, int u, int d) {
	if (r - l == 5 && d - u == 5) return true;
	return false;
}

bool isGameFail(int count, int l, int r, int u, int d) {
	if (count > maxCount) return true;
	else false;
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
		x += movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		rightCount++;
		count++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {
			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			showMessage("You are in fire!!");
		}
		printf("%d\n", count);
		//printf("%d\n", isFire(leftCount, rightCount, upCount, downCount));
	}
}
void moveLeft() {
	if (leftCount < rightCount) {
		x -= movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		leftCount++;
		count++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {

			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			showMessage("You are in fire!!");
		}

		printf("%d\n", count);
	}
}
void moveUp() {
	if (upCount < downCount) {
		y += movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		upCount++;
		count++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {

			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			showMessage("You are in fire!!");
		}
		printf("%d\n", count);
	}
}
void moveDown() {
	if (downCount - upCount < 5) {
		y -= movement;
		locateObject(start, scene1, x, y);
		locateObject(start, scene2, x, y);
		locateObject(start, scene3, x, y);
		downCount++;
		count++;
		if (isFire(leftCount, rightCount, upCount, downCount)) {

			enterScene(startScene);
			hideObject(startBtn);
			showObject(end);
			showMessage("You are in fire!!");
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
	if (object == end) endGame();

}

void timerCallback(TimerID timer) {

}

void keyboardCallback(KeyCode code, KeyState state) {
	if (!isDone) {

		if (isGameSuccess(leftCount, rightCount, upCount, downCount)) {
			showMessage("Success!!");
			showObject(next);
			showObject(next2);
			showObject(next3);
			isDone = true;
		}
		if (count >= maxCount) {
			showMessage("Fail!!");
			isDone = true;
			endGame();
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
	setTimerCallback(timerCallback);
	setKeyboardCallback(keyboardCallback);

	gameInit();

	startGame(startScene);
}