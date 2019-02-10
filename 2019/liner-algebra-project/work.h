using namespace std;

mtx add(mtx a, mtx b)
{
    mtx c;
    if (a.row != b.row || a.col != b.col) {
        printf("Error\n");
        return c;
    }
    c.row = a.row, c.col = b.col;
    for (int i = 1; i <= c.row; i++)
        for (int j = 1; j <= c.col; j++)
            c.data[i][j] = a.data[i][j] + b.data[i][j];
    return c;
}

mtx sub(mtx a, mtx b) {
    mtx c;
    if (a.row != b.row || a.col != b.col) {
        printf("Error\n");
        return c;
    }
    c.row = a.row, c.col = b.col;
    for (int i = 1; i <= c.row; i++)
        for (int j = 1; j <= c.col; j++)
            c.data[i][j] = a.data[i][j] - b.data[i][j];
    return c;
}

mtx mul(mtx a, mtx b) {
    mtx c;
    if (a.col != b.row) {
        printf("Error\n");
        return c;
    }
    c.row = a.row, c.col = b.col;
    for (int i = 1; i <= a.row; i++)
        for (int j = 1; j <= b.col; j++)
            for (int k = 1; k <= a.col; k++)
                c.data[i][j] += a.data[i][k] * b.data[k][j];
    return c;
}

double det(mtx a) {
    int &n = a.row, &m = a.col;
    if (n != m) {
        printf("Error, it is not a square matrix.\n");
        return -1;
    }
    double ans = 1;
    int cur = 1;
    for (int k = 1; k <= m && cur <= n ; k++) {
        bool ok = 0;
        for (int i = cur; i <= n; i++)
                if (fabs(a.data[i][k]) > eps) {
                ok = 1;
                if (i != cur) {
                    ans *= -1;
                    for (int j = 1; j <= m; j++)
                        swap(a.data[i][j], a.data[cur][j]);
                }
                break;
            }
        if (!ok)    continue;
        for (int i = cur + 1; i <= n; i++) {
            double times = a.data[i][k] / a.data[cur][k];
            for (int j = 1; j <= m; j++)
                a.data[i][j] -= a.data[cur][j] * times;
        }
        cur++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (fabs(a.data[i][j]) < eps)
                a.data[i][j] = 0.0;
    for (int i = 1; i <= n; i++)
        ans *= a.data[i][i];
    return ans;
}

mtx inv(mtx a) {
    mtx c;
    int &n = a.row, &m = a.col;
    if (n != m) {
        printf("Error, it is not a square matrix.\n");
        return c;
    }
    c.row = n;  c.col = m;
    for (int i = 1; i <= n; i++)
        c.data[i][i] = 1;
    int cur = 1;
    for (int k = 1; k <= m && cur <= n; k++) {
        bool ok = 0;
        for (int i = cur; i <= n; i++) {
            if (fabs(a.data[i][k]) > eps) {
                ok = 1;
                if (i != cur) {
                    for (int j = 1; j <= m; j++) {
                        swap(a.data[i][j], a.data[cur][j]);
                        swap(c.data[i][j], c.data[cur][j]);
                    }
                }
                break;
            }
        }
        if (!ok) {
            c.row = c.col = 0;
            memset(c.data, 0, sizeof(c.data));
            printf("Error, it is not a square matrix.\n");
            return c;
        }
        for (int i = 1; i <= n; i++)
            if (i != cur) {
                double times = a.data[i][k] / a.data[cur][k];
                for (int j = 1; j <= m; j++) {
                    a.data[i][j] -= a.data[cur][j] * times;
                    c.data[i][j] -= c.data[cur][j] * times;
                }
            }
        double times = a.data[cur][k];
        for (int j = 1; j <= m; j++) {
            a.data[cur][j] /= times;
            c.data[cur][j] /= times;
        }
        cur++;
    }
    return c;
}

void LU_frac(mtx a, mtx &L, mtx &U) {
    int &n = a.row, &m = a.col;
    L.row = L.col = n;
    U.row = n, U.col = m;
    int cur = 1;
//    for (int k = 1; k <= m && cur <= n; k++) {
//
//    }
}

vector<double> ct_value(mtx a) {
    vector<double> v;
    int &n = a.row, &m = a.col;
    int cur = 1;
    cout << endl;
    for (int i = 1; i <= a.row; i++)
        for (int j = 1; j <= a.col; j++)
            printf("%f%c", a.data[i][j], " \n"[j == a.col]);
    for (int k = 1; k <= m && cur <= n ; k++) {
        bool ok = 0;
        for (int i = cur; i <= n; i++)
                if (fabs(a.data[i][k]) > eps) {
                ok = 1;
                if (i != cur) {
                    for (int j = 1; j <= m; j++)
                        swap(a.data[i][j], a.data[cur][j]);
                }
                break;
            }
        if (!ok)    continue;
        for (int i = cur + 1; i <= n; i++) {
            double times = a.data[i][k] / a.data[cur][k];
            for (int j = 1; j <= m; j++)
                a.data[i][j] -= a.data[cur][j] * times;
        }
        cur++;
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (fabs(a.data[i][j]) < eps) {
                a.data[i][j] = 0;
                if (i == j)
                    ok = 0;
            }
    for (int i = 1; i <= a.row; i++)
        for (int j = 1; j <= a.col; j++)
            printf("%f%c", a.data[i][j], " \n"[j == a.col]);

    if (!ok)
        v.push_back(0);
    else
        for (int i = 1; i <= n; i++)
            v.push_back(a.data[i][i]);

}

void QR_frac(mtx a, mtx b, mtx c) {

}
