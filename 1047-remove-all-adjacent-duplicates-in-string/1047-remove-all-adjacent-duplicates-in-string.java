class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        stack.push(S.charAt(0));
        for (int i = 1; i < S.length(); i++) {
            if (!stack.isEmpty() && stack.peek() == S.charAt(i))
                stack.pop();
            else
                stack.push(S.charAt(i));
        }
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }

        sb.reverse();
        return sb.toString();
    }
}