package net.dague.astro.data;

import java.util.HashMap;
import java.util.Vector;

import net.dague.astro.util.JovianMoons;
import net.dague.astro.util.SolarSim;
import net.dague.astro.util.Vector3;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import static android.provider.BaseColumns._ID;
import static net.dague.astro.data.Constants.*;

public class SimData extends SQLiteOpenHelper {
	
	private static String[] FROM = { _ID, TIME, CALLISTO, EUROPA, GANYMEDE, IO };
	private static String ORDER_BY = TIME + " DESC" ;
	private static String WHERE_TIME = TIME + " = ?";
	private static String WHERE_RANGE = TIME + " >= ? and " + TIME + " <= ?";
	private static String WHERE_DELETE = TIME + " < ?";
	
	private static final String DATABASE_NAME = "astro.db";
	private static final int DATABASE_VERSION = 1;

	public SimData(Context context) {
		super(context, DATABASE_NAME, null, DATABASE_VERSION);
		
		// TODO Auto-generated constructor stub
	}

	public HashMap<Long, JovianMoons> getRange(long time, long until)
	{
		HashMap<Long, JovianMoons> jm = new HashMap<Long, JovianMoons>();
		// Log.i("IO", "Getting data for body: " + body + " at jd: " + jd);
		
		SQLiteDatabase db = getReadableDatabase();
		String[] wherebits = {Long.toString(time), Long.toString(until)};
		Cursor cursor = db.query(TABLE_NAME, FROM, WHERE_RANGE, wherebits, null, null, ORDER_BY);
		
		while(cursor.moveToNext()) {
			JovianMoons j = new JovianMoons();
			long dbtime = cursor.getLong(1);
			j.jd = SolarSim.JD(dbtime);
			j.callisto = cursor.getDouble(2);
			j.europa = cursor.getDouble(3);
			j.ganymede = cursor.getDouble(4);
			j.io = cursor.getDouble(5);
			jm.put(new Long(dbtime), j);
		}
		cursor.close();
		db.close();
		return jm;
	}
	
	public void purgeRecords(long time) {
		SQLiteDatabase db = getWritableDatabase();
		String [] where = {Long.toString(time)};
		db.delete(TABLE_NAME, WHERE_DELETE, where);
		db.close();
	}
	
	public void addCoords(long time, JovianMoons jm) {
		SQLiteDatabase db = getWritableDatabase();
		ContentValues values = new ContentValues();
		values.put(TIME, time);
		values.put(IO, jm.io);
		values.put(CALLISTO, jm.callisto);
		values.put(EUROPA, jm.europa);
		values.put(GANYMEDE, jm.ganymede);
		db.insertOrThrow(TABLE_NAME, null, values);
		db.close();
	}
	
	
	@Override
	public void onCreate(SQLiteDatabase db) {
		String create1 = "CREATE TABLE " + TABLE_NAME +
		"(" + _ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
		TIME + " LONG NOT NULL, " +
		CALLISTO + " DOUBLE NOT NULL, " +
		EUROPA + " DOUBLE NOT NULL, " +
		GANYMEDE + " DOUBLE NOT NULL, " +
		IO + " DOUBLE NOT NULL);";
		
		String index1 = "create index " + TABLE_NAME + "_" + TIME + 
			" on " + TABLE_NAME + "(" + TIME + ")";

		db.execSQL(create1);
		db.execSQL(index1);
		// TODO Auto-generated method stub

	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		// TODO Auto-generated method stub
		db.execSQL("DROP TABLE IF EXISTS " + TABLE_NAME);
		onCreate(db);
	}

}
