
/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    void helper(vector<vector<int>> &image, int r, int c, int initColor, int newColor, vector<vector<bool>> &vis)
    {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || vis[r][c] == true || image[r][c] != initColor)
        {
            return;
        }

        // Go to all directions
        // mark the cell as vis
        // color the cell with new color
        image[r][c] = newColor;
        vis[r][c] = true;
        helper(image, r + 1, c, initColor, newColor, vis);
        helper(image, r - 1, c, initColor, newColor, vis);
        helper(image, r, c + 1, initColor, newColor, vis);
        helper(image, r, c - 1, initColor, newColor, vis);

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size()));
        int initColor = image[sr][sc];
        helper(image, sr, sc, initColor, newColor, vis);
        return image;
    }
};
