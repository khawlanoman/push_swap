<h3 style="color:gray">This project has been created as part of the 42 curriculum by <span style="color:#28C775">khnoman</span></h3>
<h1 style="font-size: 30px; color: rgba(255, 255, 128, 0.5);">🔄 PUSH_SWAP</h1>
<br/>
<h2  style="font-size: 27px;">📋 Table of Contents</h2>
<ul>
<li><a href="#soverview"> Overview </a></li>
<li><a href="#Installation">Installation</a></li>
<li><a href="#Project_Description"> Project Description </a></li>
<li><a href="#Rules"> Rules </a></li>
<li><a href="#Project_Structure"> Project Structure </a></li>
<li><a href="#Resources"> Resources </a></li>

</ul>
<h2 style="font-size: 27px;" id="overview"> 🎯 Overview </h2>
<p> Push_swap is a program that sorts a list of integers using two stacks (a and b) and a limited set of operations.<br/>
It prints the sequence of operations needed to sort the numbers in ascending order.<br/>
The goal is to sort efficiently while handling errors and minimizing the number of moves.</p>
<div>
<h2 style="font-size: 27px;" id="Installation"> 🛠️ Installation</h2>
<h3> Clone the repository</h3>
<code> git clone < my_repositry_ulr > push_swap
<br/>
cd push_swap
</code>

<h3> compile the project</h3>
<code> make</code>

<h3> How to Run</h3>
<code>./push_swap 3 5 34 8 -3</code>

<h3>Output</h3>
<code>
pb <br/>
ra <br/>
ra <br/>
ra <br/>
pb <br/>
sa <br/>
ra <br/>
pa <br/>
ra <br/>
pa <br/>
rra
</code>
</div>
<h2 style="font-size: 27px;"id="Project_Description"> 📖 Project Description</h2>
<p>
You have two stacks named <span style="font-size: 17px; color:#28C775;">a </span>and <span style="font-size: 17px; color:#28C775;">b</span>. At the beginning:

- Stack <span style="font-size: 17px; color:#28C775;">a </span>contains a random amount of negative and/or positive numbers
- Stack <span style="font-size: 17px; color:#28C775;">b </span>is empty
- The goal is to sort the numbers in ascending order into stack <span style="font-size: 17px; color:#28C775;">a </span>

You have a set of operations (instructions) to manipulate the stacks, and you must use these operations to sort the numbers with the minimum possible moves.
</p>

<h2 style="font-size: 27px;" id="Rules"> 🎮 Rules </h2>
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

<h2 style="font-size: 27px;" id="Project_Structure">📁 Project Structure </h2>

<pre style="font-family: 'Courier New', monospace; background: #7c817875; padding: 20px; border-radius: 5px;">
push_swap/
├── main.c
├── swap.c
├── push.c
├── rotate.c
├── reverse_rotate.c
├── algo_part1.c
├──algo_part2.c
├── algo_part3.c
├── fix_index.c
├── fix_index.c
├── free_it.c
├── helper1.c
├── helper2.c
├── helper3.c
├── sorts.c
├── split.c
└── push_swap.h
├── Makefile
└── README.md
</pre>
<h2  style="font-size: 27px;" id="Resources"> 📚 Resources </h2>
<h4 style="font-size: 20px;"> Useful Links:</h4>
<ul>
<li> <a href="https://42-cursus.gitbook.io/guide/2-rank-02/push_swap"> Push_swap Tutorial (42 Docs)</a> </li>
<li> <a href="https://www.geeksforgeeks.org/dsa/stack-data-structure/"> Stack Data Structure</a></li>
<li><a href="https://www.youtube.com/watch?v=wRvipSG4Mmk&themeRefresh=1">push_swap tutorial video<a/></li>
</ul