struct point_i {
    int x, y;
    point_i () { x = y = 0; }
    point_i (int _x, int _y) : x(_x), y(_y) {}
};

struct point {
    double x, y;
    point () { x = y = 0.0; }
    point (double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point &other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct line {
    double a, b, c;
};

struct vec {
    double x, y;
    vec (double _x, double _y) : x(_x), y(_y) {}
};

double deg_to_rad (double d) { return d * M_PI / 180.0; }
double rad_to_deg (double r) { return r * 180.0 / M_PI; }

vec to_vec (const point &a, const point &b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dist (const point &p1, const point &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate (const point &p, double theta) {
    double rad = deg_to_rad(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

void points_to_line (const point &p1, const point &p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) l = {1.0, 0.0, -p1.x};
    else l = {-(double)(p1.y - p2.y) / (p1.x - p2.x), 1.0, -(double)(l.a * p1.x) - p1.y};
}

void point_slope_to_line (point p, double m, line &l) {
    l = {-m, 1.0, -((l.a * p.x) + (l.b * p.y));
}

bool are_parallel (line l1, line l2) {
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool are_same (line l1, line l2) {
    return are_parallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

bool are_intersect (line l1, line l2, point &p) {
    if (are_parallel(l1, l2)) return false;
    
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    
    return true;
}

vec scale (const vec &v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate (const point &p, const vec &v) {
    return point(p.x + v.x, p.y + v.y);
}

double dot (vec a, vec b) { return a.x * b.x + a.y * b.y; }

double norm_sq (vec v) { return v.x * v.x + v.y * v.y; }

double angle (const point &a, const point &o, const point &b) {
    vec oa = to_vec(o, a), ob = to_vec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross (vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw (point p, point q, point r) {
    return cross(to_vec(p, q), to_vec(p, r)) > EPS;
}

bool collinear (point p, point q, point r) {
    return fabs(cross(to_vec(p, q), to_vec(p, r))) < EPS;
}

double dist_to_line (point p, point a, point b, point &c) {
    vec ap = to_vec(a, p), ab = to_vec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double dist_to_line_segment (point p, point a, point b, point &c) {
    vec ap = to_vec(a, p), ab = to_vec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    
    return dist_to_line(p, a, b, c);
}

int inside_circle (const point_i &p, const point_i &c, int r) {
    int dx = p.x - c.x, dy = p.y - c.y;
    int euc = dx * dx + dy * dy, r_sq = r * r;
    if (euc < r_sq) return 1; // Dentro
    else if (euc == r_sq) return 0; // Na borda
    else return -1; // Fora
}

bool circle_two_pts_rad (point p1, point p2, double r, point &c) {
    double dist_sq = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / dist_sq - 0.25;
    
    if (det < EPS) return false;
    
    double h = sqrt(det);
    
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    
    return true;
}

double r_incircle (double ab, double bc, double ca) {
    double perimeter = ab + bc + ca
    double semiperimeter = 0.5 * perimeter;
    double area = sqrt(semiperimeter * (semiperimeter - ab) * (semiperimeter - bc) * (semiperimeter - ca));
    return area / semiperimeter;
}

double r_incircle (point a, point b, point c) {
    return r_incircle(dist(a, b), dist(b, c), dist(c, a));
}

bool incircle (point p1, point p2, point p3, point &ctr, double &r) {
    r = r_incircle(p1, p2, p3);
    
    if (fabs(r) < EPS) return false;
    
    line l1, l2;
    
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(to_vec(p2, p3), ratio / (1 + ratio)));
    points_to_line(p1, p, l1);
    
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(to_vec(p1, p3), ratio / (1 + ratio)));
    points_to_line(p2, p, l2);
    
    are_intersect(l1, l2, ctr);
    
    return true;
}

double r_circumcircle (double ab, double bc, double ca) {
    double perimeter = ab + bc + ca
    double semiperimeter = 0.5 * perimeter;
    double area = sqrt(semiperimeter * (semiperimeter - ab) * (semiperimeter - bc) * (semiperimeter - ca));
    return ab * bc * ca / (4.0 * area);
}

double r_circumcircle (point a, point b, point c) {
    return r_circumcircle(dist(a, b), dist(b, c), dist(c, a));
}

int inside_rectangle (int x, int y, int w, int h, int a, int b) {
    if (x < a && a < x + w && y < b && b < y + h) return 1; // Dentro
    else if (x <= a && a <= x + w && y <= b && b <= y + h) return 0; // Na borda
    else return -1; // Fora
}

double perimeter (const vector<point> &p) {
    double ans = 0.0;

    for (int i = 0; i < sz(p) - 1; i++) {
        ans += dist(p[i], p[i + 1]);
    }

    return ans;
}

double area (const vector<point> &p) {
    double ans = 0.0;

    for (int i = 0; i < sz(p) - 1; i++) {
        ans += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
    }

    return fabs(ans) / 2.0;
}

double area_alternative (const vetor<point> &p) {
    double ans = 0.0;
    point o(0.0, 0.0);

    for (int i = 0; i < sz(p) - 1; i++) {
        ans += cross(to_vec(o, p[i]), to_vec(o, p[i + 1]));
    }

    return fabs(ans) / 2.0;
}

bool is_convex (const vector<point> &p) {
    int n = sz(p);

    if (n <= 3) return false;

    bool first_turn = ccw(p[0], p[1], p[2]);

    for (int i = 1; i < n - 1; i++) {
        if (ccw(p[i], p[i + 1], p[(i + 2) == n ? 1 : i + 2]) != first_turn) {
            return false;
        }
    }

    return true;
}

int inside_polygon (point pt, const vector<point> &p) {
    int n = sz(p);

    if (n <= 3) return -1;

    bool on_polygon = false;

    for (int i = 0; i < n - 1; i++) {
        if (fabs(dist(p[i], pt) + dist(pt, p[i + 1]) - dist(p[i], p[i + 1])) < EPS) {
            on_polygon = true;
        }
    }

    if (on_polygon) return 0;

    double sum = 0.0;

    for (int i = 0; i < n - 1; i++) {
        if (ccw(pt, p[i], p[i + 1])) sum += angle(p[i], pt, p[i + 1]);
        else sum -= angle(p[i], pt, p[i + 1]);
    }

    return fabs(sum) > M_PI ? 1 : -1;
}

point intersection_point (point p, point q, point A, point B) {
    double a = B.y - A.y, b = A.x - B.x, c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cut_polygon (point a, point b, const vecotr<point> &q) {
    vector<point> p;

    for (int i = 0; i < sz(q); i++) {
        double left1 = cross(to_vec(a, b), to_vec(a, q[i])), left2 = 0;
        if (i != sz(q) - 1) left2 = cross(to_vec(a, b), to_vec(a, q[i + 1]));
        if (left1 > -EPS) p.pb(q[i]);
        if (left1 * left2 < -EPS) p.pb(intersection_point(q[i], q[i + 1], a, b));
    }

    if (!p.empty() && !(p.back() == p.front())) p.pb(p.front());
    return p;
}

vector<point> convex_hull (vector<point> &pts) {
    int n = sz(pts), k = 0;
    vector<point> h(2 * n);

    sort(all(pts));

    for (int i = 0; i < n; i++) {
        while (k >= 2 && !ccw(h[k - 2], h[k - 1], pts[i])) k--;
        h[k++] = pts[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && !ccw(h[k - 2], h[k - 1], pts[i])) k--;
        h[k++] = pts[i];
    }

    h.resize(k);
    return h;
}

double great_circle_dist (double p_la, double p_lo, double q_la, double q_lo, double r) {
    p_la *= M_PI / 180, p_lo *= M_PI / 180;
    q_la *= M_PI / 180, q_lo *= M_PI / 180;
    return r * acos(cos(p_la) * cos(p_lo) * cos(q_la) * cos(q_lo) + cos(p_la) * sin(p_lo) * cos(q_la) * sin(q_lo) + sin(p_la) * sin(q_la));
}