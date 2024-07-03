        stack<int> s;
        
        for (int i = 0; i < S.length(); i++) {
            // Check if the character is a digit
            if (isdigit(S[i])) {
                s.push(S[i] - '0');
            } else {
                // Otherwise, it's an operator
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                
                int ans;
                switch (S[i]) {
                    case '+':
                        ans = b + a;
                        break;
                    case '-':
                        ans = b - a;
                        break;
                    case '*':
                        ans = b * a;
                        break;
                    case '/':
                        ans = b / a;
                        break;
                }
                
                s.push(ans);
            }
        }
        
        return s.top();
