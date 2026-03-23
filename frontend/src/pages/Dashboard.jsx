import { useState } from 'react';
import TaskForm from '../components/TaskForm';
import TaskList from '../components/TaskList';
import SchedulerControls from '../components/SchedulerControls';

const Dashboard = () => {
  const [tasks, setTasks] = useState([]);

  const addTask = (task) => {
    setTasks([...tasks, task]);
  };

  const removeTask = (name) => {
    setTasks(tasks.filter((t) => t.name !== name));
  };

  return (
    <div>
      <h2>FocusForge Scheduler</h2>

      <TaskForm addTask={addTask} />
      <TaskList tasks={tasks} removeTask={removeTask} />
      <SchedulerControls tasks={tasks} />
    </div>
  );
};

export default Dashboard;
