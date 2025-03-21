class Solution {
public:
    unordered_map<string, vector<string>> ingredientsof;
    unordered_map<string, int> issupply,isrecipe, canmake;
    bool canmade(string ingredient) {
        if(!isrecipe[ingredient] && !issupply[ingredient]) return false;
        if (issupply[ingredient] || canmake[ingredient] == 2)
            return true;
        if (canmake[ingredient] == 1)
            return false;
        canmake[ingredient] = 1;
        for (auto subingredient : ingredientsof[ingredient]) {
            if (canmake[subingredient] == 1 || canmade(subingredient) == 0)
                return false;
        }
        canmake[ingredient] = 2;
        return true;
    }
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> ans;
        for (int i = 0; i < recipes.size(); i++) {
            ingredientsof[recipes[i]] = ingredients[i];
        }
        for (auto i : recipes)
            isrecipe[i] = 1;
        for (auto i : supplies)
            issupply[i] = 1;
        for (auto recipe : recipes) {
            if (canmake[recipe] == 0 && canmade(recipe)) {
                canmake[recipe] = 2;
                ans.emplace_back(recipe);
            } else if (canmake[recipe] == 2)
                ans.emplace_back(recipe);
        }
        return ans;
    }
};