# Everything currently known that doesn't work
- **Triple parentheses in expressions**\
  Example:
  ```sh
  (((hello.uppercase).lowercase).title)
  ```
  Current output:
  ```sh
  (hello.title)
  ```
  Expected output:
  ```sh
  Hello
  ```