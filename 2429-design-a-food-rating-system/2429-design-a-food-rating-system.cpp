using pii = pair<int, string>;
class Compare {
public:
    bool operator()(pii p1, pii p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
class FoodRatings {
public:
    unordered_map<string, pii> foodMap;
    unordered_map<string, set<pii, Compare>> cuisinesMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int len = foods.size();
        for (int i = 0; i < len; i++) {
            foodMap[foods[i]] = make_pair(ratings[i], cuisines[i]);
            cuisinesMap[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        pii data = foodMap[food];
        cuisinesMap[data.second].erase({data.first, food});
        cuisinesMap[data.second].insert({newRating, food});
        foodMap[food] = make_pair(newRating, data.second);
    }

    string highestRated(string cuisine) {
        return (cuisinesMap[cuisine].begin())->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */