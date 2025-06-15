#set heading(numbering: "1.")
#outline()
\ \ \ \ \ \ \ \ \ \ \ \ \ \ 


= Introduction to Python 

== What is Python?

Python is a high-level, interpreted programming language known for its simplicity and readability. Created by Guido van Rossum and released in 1991, Python has become one of the most popular languages in the world.

== Key Features of Python

    Easy to Learn and Use – Clean and readable syntax (like plain English).

    Interpreted Language – No need for compilation; you can run code directly.

    Cross-platform – Works on Windows, Linux, and macOS.

    Versatile – Used in web development, data science, AI, automation, etc.

    Large Standard Library – Comes with many built-in modules.
= Basics of Python
*1.Print Statement* 
    For displaying output

```python
 print("Hello World")
```
*2.Variable & Datatype*

No need of declaring the datatype 

*Operators*

- Arithmetic  $ + ,- ,* ,/ ,%$
- Comparison  $ == ,!= ,> ,< ,<= ,>=$

*Conditional Statements*

```python
  if age >= 18:
    print("Adult")
  else:
    print("Minor")
    
```
*Loops*

    - For loop

    ```python
 for i in range(5):
    print(i)
    ```
    - While loop
     ```python
count = 0
while count < 5:
    print(count)
    count += 1
    ```


= Strings

 // put description or shortnote of the python feature  here


   ```python
text = "Hello, World!"
print(text.upper()) 
print(text.lower()) 
print(text[0:5])
    ```

= List

// put description or shortnote of the python feature  here


    - Ordered, changeable.
       ```python
fruits = ["apple", "banana", "cherry"]
fruits.append("kiwi")
print(fruits[1]) 
    ```

= Tuple

// put description or shortnote of the python feature  here


    - Ordered, unchangeable.
    ```python
coords = (10, 20)
print(coords[0])
    ```


= Dictionary & Sets


// going for break
//ok
// put description or shortnote of the python feature  here

- Key-value pairs.
  ```python
student = {"name": "John Doe", "age": 20}
print(student["name"])
    ```

= Functions

// put description or shortnote of the python feature  here

     ```python
def greet(name):
    print("Hello", name)

greet("John Doe")
    ```


= Problem Solving

// put description or shortnote of the python feature  here
== What is Problem Solving?

Problem solving is the process of understanding a problem, designing a solution, and implementing it step by step. In programming, it's how we use logic and code to solve real-world or theoretical problems.


*Steps in Problem Solving:*

    - Understand the Problem

       - Read carefully.

      - Know what is given and what is required.

       -  Example: “Find the largest number among three given numbers.”

   -  Break the Problem Down

     -   Divide it into small, manageable steps.

      -  Example: Compare first two → then compare with third.

  - Design a Solution (Algorithm)

    -    Write steps in plain English or pseudocode.

    -   Plan how to use loops, conditions, variables, etc.

  -  Choose the Right Tools

   -     Select appropriate data structures (list, dictionary).

   -    Choose programming constructs (loop, function).

  - Write the Code

    -    Convert logic into a programming language (e.g., Python).

  - Test the Solution

    -    Try different inputs (including edge cases).

    -   Fix bugs if the output is not as expected.

  - Optimize if Needed

    -    Improve speed, reduce memory, or simplify logic.

= Introduction to Data Science

Data science is a fast-growing field that combines skills from statistics, computer science, and domain knowledge to find insights and meaning in data. In today’s digital world, data is everywhere—coming from smartphones, websites, social media, sensors, and many other sources. With so much information being created every second, it has become more important than ever to understand how to use data effectively. Data science helps organizations and individuals make better decisions by finding useful patterns and trends.

The data science process usually begins with collecting data from various sources. This could include databases, web pages, social media, or devices like sensors. Once the data is collected, it often needs to be cleaned because raw data can be messy or incomplete. Cleaning involves removing errors, filling in missing values, and organizing the data in a way that makes it easier to analyze.

After cleaning, the next step is to explore and analyze the data. This is where data scientists use statistics and visualizations to understand what the data is showing. They may look for patterns, trends, or unusual values. This part of the process helps them develop ideas about what might be happening and what questions they should try to answer. Simple charts and graphs can often reveal a lot of important information.

Once the data has been explored, data scientists often use machine learning techniques to build models that can make predictions or classify information. For example, a model could predict which customers are most likely to buy a product or help doctors identify signs of disease early. These models learn from the data and can improve over time as they are given more information.

Communication is also a key part of data science. Data scientists must be able to explain their findings clearly to people who may not have technical backgrounds. They often use visualizations like charts, dashboards, or reports to make the results easier to understand. The goal is to turn data into useful knowledge that others can act on.

Data science is now being used in nearly every industry. In healthcare, it helps improve patient care. In finance, it helps detect fraud and manage risk. In marketing, it helps companies understand their customers. As technology continues to advance and the amount of data keeps growing, data science will continue to play a major role in shaping the future. It is an exciting field with many opportunities for those who enjoy working with data and solving problems.
= Deep Learning With Tensorflow Basics

Deep learning is a branch of machine learning that focuses on using neural networks with many layers to learn from large amounts of data. It is especially powerful for tasks such as image recognition, natural language processing, and speech recognition. TensorFlow is one of the most popular open-source libraries for building and training deep learning models. Developed by Google, it provides a flexible platform for creating neural networks and running them efficiently on CPUs and GPUs.

== installation

To begin working with TensorFlow, you first need to install it using pip. Once installed, you can import it into your Python project. The basic building block of deep learning models in TensorFlow is the Keras API, which allows for the quick creation of neural networks using simple and readable code.


```sh
# Install and import TensorFlow
!pip install tensorflow
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
```
 == configuration

Next, we can create a simple neural network model using the Sequential API. This model is made of layers that process input data step-by-step. Below is an example of a simple feedforward neural network with one hidden layer:

```sh
# Create a simple neural network model
model = keras.Sequential([
    layers.Dense(64, activation='relu', input_shape=(100,)), layers.Dense(10, activation='softmax')])

# Compile the model
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

```

== training a simple model
After building and compiling the model, the next step is training it with data using the fit() function. You need input data (X_train) and corresponding labels (y_train). TensorFlow handles the training process, adjusting weights in the network to reduce prediction errors. With its simple syntax and powerful capabilities, TensorFlow makes it easy to get started with deep learning and build more complex models as you gain experience.
```sh
# Example dummy data
import numpy as np
X_train = np.random.random((1000, 100))
y_train = np.random.randint(10, size=(1000,))

# Train the model
model.fit(X_train, y_train, epochs=5, batch_size=32)
```
This basic introduction covers the core steps: installing TensorFlow, building a simple model, compiling it, and training it with data. As you dive deeper, you can explore more advanced features like convolutional neural networks (CNNs), recurrent neural networks (RNNs), and customizing your own training loops. TensorFlow offers both simplicity and depth, making it ideal for both beginners and professionals in deep learning.


= ANN Guided Project Regression

Regression is a statistical and machine learning technique used to model and analyze the relationship between a dependent variable (what you want to predict) and one or more independent variables (the inputs or features). The main goal of regression is to find a mathematical function that best fits the data so that we can predict the outcome for new inputs.

== Regression types

Simple Linear Regression: Involves one independent variable and one dependent variable.
Multiple Linear Regression: Involves two or more independent variables.
There are also non-linear and advanced types (like polynomial, logistic, ridge, etc.), but at its core, regression is about predicting a continuous value.

1. Simple Linear Regression: involves one independent variable and one dependent variable
2. Multiple Linear Regression: Involves two or more independent variables.

There are also non-linear and advanced types (like polynomial, logistic, ridge, etc.), but at its core, regression is about predicting a continuous value.

== Linear Regression
in linear regression, the relationship between the inputs X and output Y is modeled by a straight line
$ y = m x + b $

where:
- $x$:  predicted value (dependent variable)
- $y$:  input value (independent variable)
- $m$:  slope of the line (shows how much $x$ changes with $y$)
- $b$:  y-intercept (value of $x$ when $x$=0)

in multiple Regression; with several inputs $x_1,x_2...., x_n,$ the equation becomes

$
y = b_0 + b_1 x_1 + b_2 x_2 + \ldots + b_n x_n
$

where:
$b_0$ is the intercept,

$b_1, b_2,...b_n$ are coefficients for each feature.


== Use of Regression



The goal is to find the best coefficients (slopes and intercepts) that make the predicted values as close as possible to the actual values. This is done by minimizing the error between predicted and actual outcomes.

The most common way to measure error is the Mean Squared Error:

$ "MSE" = 1 / n sum_(i=1)^(n) (y_i - y^and_i)^2 $

where: 
$y_i:$ actual value,

$y^and_i:$ predicted value,

$n: $ number of data points

minimize the error gives us the best-fit line

== Regression Advantages:

Prediction: Forecast future values (e.g., housing prices, sales, etc.).

Understanding relationships: Learn how variables influence each other.

Decision-making: Support business, medical, and financial decisions with data-backed insights.

 

= Basic Regresion Model 

in regression, we try to learn  the relationship between input and output values. for example, if you know a simple rule like

$
y = 2 x + 1
$

We want a model that can learn this rule just by looking at example values of $x$ and their matching $y$ values. Once it learns this pattern, it can predict new values, like if $x$ = 10, then $y$ = 21.

*Design a simple Model*

In TensorFlow, we build a model using layers. For simple linear regression, we only need one Dense layer with:
 -   One input (x value)
-  One output (y value)

This layer automatically tries to find the best weight and bias — in other words, 
the best values for the equation:
$
y = w x + b
$

where:
$w$ is the weight (x value)

$b$ is the bais (intercept)

* build & compile *

Before training, the model needs to know:

- How to learn: This is done using an optimizer like SGD (Stochastic Gradient Descent).

- What to learn: The model measures its error using a loss function like Mean Squared Error (MSE), which tells it how far off its predictions are from the real values.

*training the model*

Now, we show the model pairs of $x$ and $y$ values many times (these are called epochs). Each time, it adjusts its internal numbers (weights and bias) to get better at predicting.

Over time, it gets closer and closer to understanding the correct pattern.

= Classification With ANN

== Structure of ANN:

A basic feedforward neural network (FFNN) includes:

- Input layer: Takes the feature vector xx

- Hidden layer(s): Applies transformations using weights and activation functions

- Output layer: Produces probabilities for each class

#image("Neural-Networks-Architecture.png")

a. *forward propagation*

each neuron performs this operation 

$
z = w^t x + b 
$
where: 
$w$: weight vector

$b$: bias term

$z$: linear combination of inputs

Then, an *activation function* (like ReLU or sigmoid) is applied:


#align(center)[i. sigmoid function: $sigma(x) = 1 / (1 + e^(-x))$]
#figure(
  image("sigmoid.png", width: 60%),
  caption: [A sigmoid function]
) <sigmoid>

#align(center)[ii. rectified linear unit: $a =phi(z)$]

#figure(
  image("relu.png", width: 60%),
  caption: [A Relu function]
) <relu>


This continues through the layers until the *output layer*.

Output Layer – *Softmax Function*

For classification, especially multiclass, the output layer often uses the softmax function to convert raw scores into probabilities:

== Training a Feedforward Neural Network

Training a Feedforward Neural Network involves adjusting the weights of the neurons to minimize the error between the predicted output and the actual output. This process is typically performed using backpropagation and gradient descent.

    Forward Propagation: During forward propagation the input data passes through the network and the output is calculated.
    Loss Calculation: The loss (or error) is calculated using a loss function such as Mean Squared Error (MSE) for regression tasks or Cross-Entropy Loss for classification tasks.
    Backpropagation: In backpropagation the error is propagated back through the network to update the weights. The gradient of the loss function with respect to each weight is calculated and the weights are adjusted using gradient descent

    === What is Gradient Descent?


#figure(
  image("gradientdesent.png", width: 60%),
  caption: [Linear Regression using Gradient Descent]
) <relu>


Gradient descent is an optimization algorithm used in machine learning to minimize the cost function by iteratively adjusting parameters in the direction of the negative gradient, aiming to find the optimal set of parameters.

The cost function represents the discrepancy between the predicted output of the model and the actual output. Gradient descent aims to find the parameters that minimize this discrepancy and improve the model’s performance.

The algorithm operates by calculating the gradient of the cost function, which indicates the direction and magnitude of the steepest ascent. However, since the objective is to minimize the cost function, gradient descent moves in the opposite direction of the gradient, known as the negative gradient direction.

By iteratively updating the model’s parameters in the negative gradient direction, gradient descent gradually converges towards the optimal set of parameters that yields the lowest cost. The learning rate, a hyperparameter, determines the step size taken in each iteration, influencing the speed and stability of convergence.

Gradient descent can be applied to various machine learning algorithms, including linear regression, logistic regression, neural networks, and support vector machines. It provides a general framework for optimizing models by iteratively refining their parameters based on the cost function.
    
== Mean Squared Error (MSE)

we use Mean Squared Error (MSE) as the *cost function* for a model that implements a linear regression and to make the Mean Squared Error more accurate by training the model. which is done by gradient descent

$ J(w,b) = 1 / (2m) sum_(i=1)^(m) (y_i - y^and_i)^2 = 1 / (2m) sum_(i=1)^(m) (w x ^((i)) + b + y^((i)))^2 
 $

==  Gradient Descent

Gradient descent minimizes $ J(w,b)$ by updating the parameters $w$ and $b$ iteratively using the gradients of the cost function.
1. Compute Gradients:
$
(∂J) / (∂w) = 1 / m sum_(i = 1)^m (w x^i + b + y^i)x^i
$


$
(∂J) / (∂b) = 1 / m sum_(i = 1)^m (w x^i + b + y^i)
$

2. Update Parameter:

$
w := w - alpha (∂J) / (∂w)
$


$
b := b - alpha  (∂J) / (∂b)
$

where $alpha$ is the *learning rate*,a very small positive integer that controls how big each step is 

..
= Classification With CNN \


#image("cnn.png")



  == CNN Architecture for Classification (Step-by-Step)

   === Input Layer

        Takes in the raw pixel values of an image.

        Example: A 32x32 RGB image would have a shape of (32, 32, 3).
  === Convolutional Layers

        Apply filters (kernels) to the image to detect local features like edges, textures, shapes.

        Output: Feature maps showing the presence of features in different parts of the image.
   === Activation Function (usually ReLU)

        Introduces non-linearity so the network can learn complex patterns.

        ReLU(x) = max(0, x)
   === Pooling Layers (usually Max Pooling)

        Reduce the spatial dimensions (downsampling).

        Keeps the most important information while reducing computation.
  ===  Fully Connected (Dense) Layers

        Flatten the feature maps into a 1D vector.

        Combine features to make predictions.

        Similar to traditional neural networks at this point.
   === Output Layer

        Uses a softmax activation function (for multi-class classification).

        Outputs a probability distribution across classes.

        The class with the highest probability is chosen as the prediction.

= Guided Project – Binary Classification

 How Binary Classification Works in a Neural Network
-  Input Layer

    Receives raw data (e.g., image, text, or features).

- Hidden Layers

    These can include convolutional layers (in CNNs), dense layers, activations like ReLU.

    The network learns patterns/features from input data.

- Output Layer

    A single neuron is used in the output layer.

    Activation Function: Sigmoid

        It squashes the output to a value between 0 and 1.

        Output represents the probability of the positive class.

        $
        sigma(x) = 1 / (1 + e^(-x))
        $

    If output > 0.5 → Predict Class 1
    
    If output ≤ 0.5 → Predict Class 0

- *Loss Function*

    The most common loss function for binary classification is Binary Cross-Entropy Loss:
    
$
"Loss" = -[y. log(y^and) +  ( 1 - y) . log(1 - y^and)]
$

    Where:

        $y$ is the actual label (0 or 1)

        $y^and$​ is the predicted probability

 - *Simple Binary Classification in Code (TensorFlow)*

 ```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

model = Sequential([
    Dense(16, activation='relu', input_shape=(input_dim,)),
    Dense(1, activation='sigmoid')  # Sigmoid for binary classification
])

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

 ```
 
= CNN Guided Project - Multiclass Classification

 How Multiclass Classification Works (especially with Neural Networks / CNNs)
1. Input Layer

    Takes in the raw input data (e.g., image pixels, text features, etc.).

2. Hidden Layers

    CNNs extract hierarchical features (edges → shapes → objects).

    These features are passed through dense layers.

3. Output Layer

    The number of neurons in the output layer equals the number of classes.

    Activation Function: Softmax

        Converts the output to a probability distribution across all classes.

$
"Softmax"(z_i) = e^(z_i) / ((sum_(j = 1)^K)e^(z_j))
$
Where $K$ is the number of classes.


Loss Function

    Use Categorical Cross-Entropy Loss for one-hot encoded labels:


$
"Loss" = - sum_(i = 1)^K y_i log(y^and_i)
$

If labels are integer encoded (e.g., 0, 1, 2), use Sparse Categorical Cross-Entropy.


- *Code Example (TensorFlow - 3 Classes)*
```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

model = Sequential([
    Dense(64, activation='relu', input_shape=(input_dim,)),
    Dense(3, activation='softmax')  # 3 classes, softmax activation
])

model.compile(optimizer='adam',
              loss='categorical_crossentropy',
              metrics=['accuracy'])
```



