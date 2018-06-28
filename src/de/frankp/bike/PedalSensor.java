package de.frankp.bike;

public class PedalSensor {

	/**
	 * configured number of pulses per crank turn, change via #setPulsesPerTurn()
	 */
	private long iPulsesPerTurn = 4;
	private long iTotalTurns = 0;
	private long iTripTurns = 0;

	private long ulTripStartMillies = 0;
	private long ulLastCrankTurnMillies = 0;
	/** time when the last turn occur */
	private long ulLastCrankTurnTime = 0;

	private int iPulses = 0; // count pulses per turn
	private boolean tripActive = false;

	public PedalSensor() {
		super();
	}

	/**
	 * this function is called when the pedaling Hall Sensor recognizes a magnetic
	 * pulse. For every turn of the crank I have 4 magnets, this means 4 pulses is
	 * exactly one turn of the crank.
	 */
	public void interruptServiceRoutine() {
		interruptServiceRoutine(System.currentTimeMillis());
	}

	public void interruptServiceRoutine(long millis) {

		// register next pulse
		iPulses++;

		if (this.iPulses == 1) {
			this.ulLastCrankTurnTime = millis;
		}

		if (this.iPulses >= this.iPulsesPerTurn) {
			// one turn is complete
			iPulses = 0;
			turn(millis);
		}
	}

	/** administrative */
	public void setPulsesPerTurn(int pulsesPerTurn) {
		this.iPulsesPerTurn = pulsesPerTurn;
	}

	/**
	 * this function should be called whenever a new trip is started
	 */
	public void startTrip() {
		startTrip(System.currentTimeMillis());
	}

	public void startTrip(long millis) {
		if (tripActive) {
			return;
		}
		this.iTripTurns = 0;
		this.ulTripStartMillies = millis;
		this.tripActive = true;
	}

	/** this function should be called whenever a trip ends */
	public void endTrip() {
		this.tripActive = false;
	}

	/** returns the total number of crank turns since starting */
	public long getTotalTurns() {
		return iTotalTurns;
	}

	/**
	 * set the previous value as the application should save it's state when powered
	 * off and recover the value when powered on
	 */
	public void initTotalTurns(long totalTurns) {
		this.iTotalTurns = totalTurns;
	}

	/** get the current number of crank turns for the current trip */
	public long getTripTurns() {
		return iTripTurns;
	}

	/** administrative */
	public void setPulsesPerTurn(long pulsesPerTurn) {
		this.iPulsesPerTurn = pulsesPerTurn;
	}

	/** administrative */

	public long getPulsesPerTurn() {
		return iPulsesPerTurn;
	}

	/**
	 * returns the current crank speed in 1/minute probably an average over the last
	 * x turns
	 */
	public float getCurrentCrankFrequency() {
		return 0.0f;
	}

	/** returns the crank speed in 1/minute */
	public float getTripAverageCrankFrequency() {
		return getTripAverageCrankFrequency(System.currentTimeMillis());
	}
	public float getTripAverageCrankFrequency(long millis) {
		if (!tripActive) {return 0.0f;}
// trip is active
		
		if (iTripTurns == 0 ) {return 0.0f;}
		
		return iTripTurns / millis;
	}	

	/** returns the minimum crank speed in 1/minute for the trip */
	public float getTripMinCrankFrequency() {
		return 0.0f;
	}

	/** returns the maximum crank speed in 1/minute for the trip */
	public float getTripMaxCrankFrequency() {
		return 0.0f;
	}

	/** optional: returns the average crank speed in 1/minute */
	public float getTotalAverageCrankFrequency() {
		return 0.0f;
	}

	/** optional: returns the minimum crank speed in 1/minute total */
	public float getTotalMinCrankFrequency() {
		return 0.0f;
	}

	/** optional: returns the maximum crank speed in 1/minute total */
	public float getTotalMaxCrankFrequency() {
		return 0.0f;
	}

	protected void turn(long millis) {
		// calculate time for last turn
		ulLastCrankTurnMillies = millis - ulLastCrankTurnTime;

	}

}
