from flask import Flask, render_template, request
from datetime import datetime
import random
#import serial
import datetime
labels = []
values = []
iterator = [0]
#ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)
app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def home():
    """"
   # ser.write(b'status\n')
    temp = random.randint(14,40) #ser.readline().decode("utf-8").strip()
    hora = datetime.datetime.now()
    horaFormato = f'{hora.hour}:{hora.minute}:{hora.second}'
    legend = 'Temperatura'
    if (len(labels) <= 20): 
        labels.append(horaFormato)
        values.append(temp)
    labels.pop()
    values.pop()
    labels.append(horaFormato)
    values.append(temp)
    print(labels)
    print(values)
    """
    return render_template("index.html")#, values=values, labels=labels, legend=legend)

@app.route('/adelante')
def adelante():
#    ser.write(b'set on\n')
    print("adelante")
    return ("true")

@app.route('/atras')
def atras():
 ##   ser.write(b'set back\n')
    print("atras")
    return ("true")

@app.route('/izquierda')
def izquierda():
#    ser.write(b'set left\n')
    print("izquierda")
    return ("true")
    
@app.route('/derecha')
def derecha():
#    ser.write(b'set rigth\n')
    print("derecha")
    return ("True")

@app.route('/detener')
def detener():
#    ser.write(b'set off\n')
    print("detener")
    return ("true")

@app.route("/graph_temp")
def graph():
   # ser.write(b'status\n')
    temp = random.randint(14,40) #ser.readline().decode("utf-8").strip()
    hora = datetime.datetime.now()
    horaFormato = f'{hora.hour}:{hora.minute}:{hora.second}'
    legend = 'Temperatura'
    if (len(labels) <= 20): 
        labels.append(horaFormato)
        values.append(temp)
    labels.pop()
    values.pop()
    labels.append(horaFormato)
    values.append(temp)
    if(temp >= 30):
        return render_template("peligro.html", values=values, labels=labels, legend=legend)
    print(labels)
    print(values)
    return render_template("graph.html", values=values, labels=labels, legend=legend)  
if __name__ == "__main__":
    app.run(host= "0.0.0.0", port= 8000)

