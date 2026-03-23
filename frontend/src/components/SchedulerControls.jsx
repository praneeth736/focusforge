const SchedulerControls = ({ tasks }) => {
  const runScheduler = (mode, algo = 'AUTO') => {
    if (tasks.length === 0) {
      alert('No tasks to schedule');
      return;
    }

    console.log('Running scheduler');
    console.log('Mode:', mode);
    console.log('Algorithm:', algo);
    console.log('Tasks:', tasks);

    alert(`Scheduler started in ${mode} mode (${algo})`);
  };

  return (
    <div style={{ marginTop: '20px' }}>
      <h3>Run Scheduler</h3>

      <button onClick={() => runScheduler('AUTO')}>
        Run AUTO Scheduler
      </button>

      <div style={{ marginTop: '10px' }}>
        <button onClick={() => runScheduler('MANUAL', 'FCFS')}>FCFS</button>
        <button onClick={() => runScheduler('MANUAL', 'SJF')}>SJF</button>
        <button onClick={() => runScheduler('MANUAL', 'PRIORITY')}>Priority</button>
        <button onClick={() => runScheduler('MANUAL', 'ROUND_ROBIN')}>Round Robin</button>
        <button onClick={() => runScheduler('MANUAL', 'SRTF')}>SRTF</button>
        <button onClick={() => runScheduler('MANUAL', 'MLFQ')}>MLFQ</button>
      </div>
    </div>
  );
};

export default SchedulerControls;
