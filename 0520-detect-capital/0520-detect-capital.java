class Solution {
    public boolean detectCapitalUse(String word) {
        String cp1,cp2,cp3;
        cp1=cp2=cp3=word;
        
        cp3 = cp3.substring(0,1).toUpperCase() + cp3.substring(1).toLowerCase();
        
        return cp1.toUpperCase().equals(word) || cp1.toLowerCase().equals(word) || cp3.equals(word);
    }
}