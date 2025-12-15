<h1 style="font-size: 30px; color: rgba(255, 255, 128, 0.5);">🔄 PUSH_SWAP</h1>
<br/>
<h2 style="font-size: 27px;"> 🎯 Overview </h2>
<p> Push_swap is a program that sorts a list of integers using two stacks (a and b) and a limited set of operations.<br/>
It prints the sequence of operations needed to sort the numbers in ascending order.<br/>
The goal is to sort efficiently while handling errors and minimizing the number of moves.</p>

<h2 style="font-size: 27px;"> 📖 Project Description</h2>
<p>
You have two stacks named <span style="font-size: 17px; color:#28C775;">a </span>and <span style="font-size: 17px; color:#28C775;">b</span>. At the beginning:

- Stack <span style="font-size: 17px; color:#28C775;">a </span>contains a random amount of negative and/or positive numbers
- Stack <span style="font-size: 17px; color:#28C775;">b </span>is empty
- The goal is to sort the numbers in ascending order into stack <span style="font-size: 17px; color:#28C775;">a </span>

You have a set of operations (instructions) to manipulate the stacks, and you must use these operations to sort the numbers with the minimum possible moves.
</p>

<h2 style="font-size: 27px;"> 🎮 Rules </h2>
<h3>Allowed Operations: </h3>
<table border="1">
  <tr>
    <th>Operation</th>
    <th>Name</th>
    <th>Description</th>
  </tr>
  <tr style="background-color: rgba(255, 255, 128, 0.5)">
    <td><b>sa</b></td>
    <td>swap a</td>
    <td>swap first 2 elements of stack a</td>
  </tr>
  <tr>
    <td><b>sb</b></td>
    <td>swap b</td>
    <td>swap first 2 elements of stack b</td>
  </tr>
  <tr style="background-color: rgba(255, 255, 128, 0.5)">
    <td><b>ss</b></td>
    <td>swap both</td>
    <td>sa and sb at the same time</td>
  </tr>
  <tr>
    <td><b>pa</b></td>
    <td>push a</td>
    <td>take first element from b and put it on top of a</td>
  </tr>
  <tr style="background-color: rgba(255, 255, 128, 0.5)">
    <td><b>pb</b></td>
    <td>push b</td>
    <td>take first element from a and put it on top of b</td>
  </tr>
  <tr>
    <td><b>ra</b></td>
    <td>rotate a</td>
    <td>shift all elements of stack a up by 1 (first becomes last)</td>
  </tr>
  <tr style="background-color: rgba(255, 255, 128, 0.5)">
    <td><b>rb</b></td>
    <td>rotate b</td>
    <td>shift all elements of stack b up by 1 (first becomes last)</td>
  </tr>
  <tr>
    <td><b>rr</b></td>
    <td>rotate both</td>
    <td>ra and rb at the same time</td>
  </tr>
  <tr style="background-color: rgba(255, 255, 128, 0.5)">
    <td><b>rra</b></td>
    <td>reverse rotate a</td>
    <td>shift all elements of stack a down by 1 (last becomes first)</td>
  </tr>
  <tr>
    <td><b>rrb</b></td>
    <td>reverse rotate b</td>
    <td>shift all elements of stack b down by 1 (last becomes first)</td>
  </tr>
  <tr style="background-color: rgba(255, 255, 128, 0.5)">
    <td><b>rrr</b></td>
    <td>reverse rotate both</td>
    <td>rra and rrb at the same time</td>
  </tr>
</table>



<h2  style="font-size: 27px;"> 📚 Resources </h2>
<h4 style="font-size: 20px;"> Useful Links:</h4>
<ul>
<li> <a url="https://42-cursus.gitbook.io/guide/2-rank-02/push_swap"> Push_swap Tutorial (42 Docs)</a> </li>
<li> <a url="https://www.geeksforgeeks.org/dsa/stack-data-structure/"> Stack Data Structure</a></li>

</ol>