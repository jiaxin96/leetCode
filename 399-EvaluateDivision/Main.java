public static double[] calcEquation(String[][] equations, double[] values, String[][] query) {
        Map<String, Map<String, Double>> numMap = new HashMap<>();
        int i = 0;
        for(String[] str : equations) {
            insertPairs(numMap, str[0], str[1], values[i]);
            insertPairs(numMap, str[1], str[0], 1.0/values[i]);
            i++;
        }

        double[] res = new double[query.length];
        i = 0;
        for(String[] q: query) {
            Double resObj = handleQuery(q[0], q[1], numMap, new HashSet<>());
            res[i++] = (resObj != null) ? resObj : -1.0;
        }
        return res;
    }

    public static void insertPairs(Map<String, Map<String, Double>> numMap, String num, String denom, Double value) {
        Map<String, Double> denomMap = numMap.get(num);
        if(denomMap == null) {
            denomMap = new HashMap<>();
            numMap.put(num, denomMap);
        }
        denomMap.put(denom, value);
    }

    public static Double handleQuery(String num, String denom, Map<String, Map<String, Double>> numMap, Set<String> visitedSet) {
        String dupeKey = num+":"+denom;
        if(visitedSet.contains(dupeKey)) return null;
        if(!numMap.containsKey(num) || !numMap.containsKey(denom)) return null;
        if(num.equals(denom)) return 1.0;

        Map<String, Double> denomMap = numMap.get(num);
        visitedSet.add(dupeKey);
        for(String key : denomMap.keySet()) {

            Double res = handleQuery(key, denom, numMap, visitedSet);
            if(res != null) {
                return denomMap.get(key) * res;
            }
            
        }
        visitedSet.remove(dupeKey);
        return null;
    }