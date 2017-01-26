from flask import Flask, render_template
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

@app.route("/drvo")
def drvo():
    return "Hello drvo!"

@app.route('/zdravo/')
@app.route('/zdravo/<name>')
def zdravo(name=None):
    return render_template('template.html', name=name)


if __name__ == "__main__":
    app.run()
