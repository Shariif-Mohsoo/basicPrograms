/*
 *  class in js
 */
//super class
class Pet {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }
  eat() {
    const { name } = this;
    console.log(`${name} is eating`);
  }
  sleep() {
    const { name } = this;
    console.log(`${name} is sleeping`);
  }
  walk() {
    const { name } = this;
    console.log(`${name} is walking`);
  }
  aged() {
    const { name, age } = this;
    console.log(`${name} is of age: ${age}`);
  }
}
//sub class 1; For inheritance (extend) keyword will be used.
class Dog extends Pet {
  bark() {
    console.log("WOOOOF!!!!");
  }
}
//sub class 2; For inheritance (extend) keyword will be used.
class Cat extends Pet {
  meow() {
    console.log("MEOOWWW!!!!!");
  }
}

const cat = new Cat("Freya", 8);
cat.eat();
cat.sleep();
cat.walk();
cat.aged();
const dog = new Dog("Granger", 8);
dog.eat();
dog.sleep();
dog.walk();
dog.aged();
