/*
TODO:
   MOHSOO LET'S HOOK WITH CONSTRUCTOR FUNCTIONS. 
*/
function GenerateColor(r, g, b) {
  this.r = r;
  this.g = g;
  this.b = b;
}
GenerateColor.prototype.rgb = function () {
  const { r, g, b } = this;
  return `rgb(${r},${g},${b})`;
};
GenerateColor.prototype.rgba = function (a = 1.0) {
  const { r, g, b } = this;
  return `rgba(${r},${g},${b},${a})`;
};
GenerateColor.prototype.hex = function () {
  const { r, g, b } = this;
  return "#" + ((1 << 24) + (r << 16) + (g << 8) + b).toString(16).slice(1);
};
/*
    WHAT DOES THE NEW DO?
    1-) It will create the new blank JS Object.
    const obj = new functionCall(param);
*/
const red = new GenerateColor(255, 0, 0);
console.log(red.rgb());
console.log(red.rgba());
console.log(red.hex());
