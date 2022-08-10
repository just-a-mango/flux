# 📚 Flux Documentation
### Expressions
```
- (obj.property)
- (obj.property)+(other_obj.property)
- obj+ second_obj
```

All existing properties:
- ```uppercase```: upper case the string
- ```lowercase```: lower case the string
- ```isnumbers```: returns ```true``` or ```false``` based on if the string only contains numbers
- ```isletters```: returns ```true``` or ```false```based on  if the string only contains letters
- ```capitalize```: capitalizes the first character of the string
- ```isuppercase```: returns ```true``` or ```false``` based on if all the characters in the string are uppercase
- ```islowercase```: returns ```true``` or ```false``` based on if all the characters in the string are lowercase
- ```strip```: removes all trailing and leading whitespaces from the string
- ```bold```: makes the string bold
- ```<color>```: makes the string (any color)
- ```<color>_bg```: makes the string's background (any color)
- ```<color>_bold```: makes the string's background (any color) and bold
- Many more coming in the future..

Examples:
- ```sh
    (world.uppercase)
    ```
- ```sh
    (hello.title)+ (world.title)
    ```
- ```sh
    (hello.uppercase)+ (world.uppercase)
    ```
- ```sh
    (hello.title)+ (world.white_bg_bold)
    ```



### Declaring variables
```sh
var <name> = <expression>
```

Examples:
- ```sh
    var world = Hello World !
    ```
- ```sh
    var name = usr_in(What is your name ?)
    ```
- ```sh
    var name = (Hello.uppercase)+ WORLD !
    ```
- ```sh
    var one = Hello
    var two = World
    var three = !
    var sum = one+ two+ three
    ```

### Printing to the terminal
```sh
print -> <expression>
```
Examples:
- ```sh
    print -> Hello World!
    ```
- ```sh
    print -> usr_in(>> )
    ```
- ```sh
    var world = Hello World !
    print -> (var)world
    ```
- ```sh
    print -> (hello.uppercase)+ (WORLD.lowercase)+ !
    ```
- ```sh
    var one = Hello
    var two = World
    var three = !
    print -> (var)one+ (var)two+ (var)three
    ```