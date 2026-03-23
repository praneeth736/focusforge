import { useState } from 'react';

const TaskForm = ({ addTask }) => {
  const [name, setName] = useState('');
  const [burst, setBurst] = useState('');
  const [priority, setPriority] = useState('');
  const [arrival, setArrival] = useState('');

  const submitTask = (e) => {
    e.preventDefault();

    if (!name || !burst) {
      alert('Task name and burst time are required');
      return;
    }

    addTask({
      name,
      burst: Number(burst),
      priority: Number(priority) || 0,
      arrival: Number(arrival) || 0,
      queue_level: 0,
    });

    // reset form
    setName('');
    setBurst('');
    setPriority('');
    setArrival('');
  };

  return (
    <form onSubmit={submitTask} style={{ marginBottom: '20px' }}>
      <h3>Add Task</h3>

      <input
        placeholder="Task Name"
        value={name}
        onChange={(e) => setName(e.target.value)}
      />

      <input
        type="number"
        placeholder="Burst Time"
        value={burst}
        onChange={(e) => setBurst(e.target.value)}
      />

      <input
        type="number"
        placeholder="Priority"
        value={priority}
        onChange={(e) => setPriority(e.target.value)}
      />

      <input
        type="number"
        placeholder="Arrival Time"
        value={arrival}
        onChange={(e) => setArrival(e.target.value)}
      />

      <button type="submit">Add Task</button>
    </form>
  );
};

export default TaskForm;
