const double eps = 1e-6;

typedef struct matrix {
    int row, col;
    double data[105][105];
    matrix() {
        memset(data, 0, sizeof(data));
        row = col = 0;
    }
} mtx;

mtx add(mtx a, mtx b);
mtx sub(mtx a, mtx b);
mtx mul(mtx a, mtx b);
