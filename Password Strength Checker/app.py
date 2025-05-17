from flask import Flask, render_template, request, jsonify
import re

app = Flask(__name__)

def calculate_password_strength(password):
    # Criteria for strength
    length = len(password) >= 12
    has_upper = bool(re.search(r'[A-Z]', password))
    has_lower = bool(re.search(r'[a-z]', password))
    has_digit = bool(re.search(r'\d', password))
    has_special = bool(re.search(r'[!@#$%^&*(),.?":{}|<>]', password))

    # Common patterns check
    common_patterns = ["123456", "password", "qwerty", "admin"]
    common = any(pattern in password.lower() for pattern in common_patterns)

    # Scoring the password on the basis of criteria
    score = sum([length, has_upper, has_lower, has_digit, has_special]) - int(common)

    if score < 3:
        strength = "Weak"
    elif score < 5:
        strength = "Moderate"
    else:
        strength = "Strong"

    return {
        "strength": strength,
        "details": {
            "length": "Good" if length else "Too short (12+ chars recommended)",
            "uppercase": "Contains uppercase" if has_upper else "Missing uppercase letters",
            "lowercase": "Contains lowercase" if has_lower else "Missing lowercase letters",
            "digit": "Contains numbers" if has_digit else "Missing numbers",
            "special": "Contains special characters" if has_special else "Missing special characters",
            "common_patterns": "Contains common patterns" if common else "No common patterns detected"
        }
    }

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/assess_password", methods=["POST"])
def assess_password():
    data = request.json
    password = data.get("password")
    if not password:
        return jsonify({"error": "Password is required"}), 400

    result = calculate_password_strength(password)
    return jsonify(result)

if __name__ == "__main__":
    app.run(debug=True)
