#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function to get the current mouse position
void get_mouse_position(int *x, int *y) {
    POINT cursor_position;
    GetCursorPos(&cursor_position);
    *x = cursor_position.x;
    *y = cursor_position.y;
}

// Function to move the mouse cursor to a specific position
void move_mouse(int x, int y) {
    SetCursorPos(x, y);
}

// Function to click the left mouse button
void left_click() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

// Function to click the right mouse button
void right_click() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
}

// Function to scroll the mouse wheel
void mouse_wheel_scroll(int delta) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = delta;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    int x, y;
    get_mouse_position(&x, &y);
    printf("Current mouse position: (%d, %d)\n", x, y);

    move_mouse(100, 200);
    printf("Mouse moved to (100, 200)\n");

    left_click();
    printf("Left mouse button clicked\n");

    right_click();
    printf("Right mouse button clicked\n");

    mouse_wheel_scroll(120);
    printf("Mouse wheel scrolled down\n");

    return 0;
}
