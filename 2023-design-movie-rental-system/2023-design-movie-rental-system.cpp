class MovieRentingSystem {
public:
    unordered_map<long long, int> shopMovieDb;    // (shop+movie) => price
    unordered_map<int, set<pair<int,int>>> movieDb; // movie => {price,shop}
    set<vector<int>> rented; // rented movies {price,shop,movie}
    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | (long long)movie;
    }
    int noOfShops;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        noOfShops = n;
        for (auto entry : entries) {
            int price = shopMovieDb[encode(entry[0], entry[1])];
            if (price == 0) {
                shopMovieDb[encode(entry[0], entry[1])] = entry[2];
                movieDb[entry[1]].insert({entry[2], entry[0]});
            }
        }
    }

    vector<int> search(int movie) {
        auto& shopList = movieDb[movie];
        vector<int> shops;
        int req = 5;
        for (auto it = shopList.begin(); it != shopList.end() && req > 0;
             it++, req--) {
            shops.push_back(it->second);
        }
        return shops;
    }

    void rent(int shop, int movie) {
        int price = shopMovieDb[encode(shop, movie)];
        movieDb[movie].erase({price, shop});
        rented.insert({price, shop, movie});
        shopMovieDb[encode(shop, movie)] = -price;
    }

    void drop(int shop, int movie) {
        int price = -shopMovieDb[encode(shop, movie)];
        movieDb[movie].insert({price, shop});
        rented.erase({price, shop, movie});
        shopMovieDb[encode(shop, movie)] = price;
    }

    vector<vector<int>> report() {
        vector<vector<int>> reports;
        int req = 5;
        for (auto it = rented.begin(); it != rented.end() && req > 0;
             it++, req--) {
            reports.push_back({(*it)[1], (*it)[2]});
        }
        return reports;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */