/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool isUniform(vector<vector<int>>& grid, int x, int y, int len) {
        int val = grid[x][y];
        for (int i = x; i < x + len; ++i) {
            for (int j = y; j < y + len; ++j) {
                if (grid[i][j] != val) return false;
            }
        }
        return true;
    }

    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        if (isUniform(grid, x, y, len)) {
            return new Node((grid[x][y] == 1), true);
        }

        int half = len / 2;
        Node* node = new Node(false, false);
        node->topLeft = build(grid, x, y, half);
        node->topRight = build(grid, x, y + half, half);
        node->bottomLeft = build(grid, x + half, y, half);
        node->bottomRight = build(grid, x + half, y + half, half);
        return node;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};